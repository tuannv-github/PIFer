#include "mode_run.h"
#include "ui_mode_run.h"

#include <limits>
#include <DWA/dwa.h>
#include <DWA/dwa_utils.h>
#include <EKF/ekf_utils.h>

Mode_run::Mode_run(QWidget *parent, CommonObject *co) :
    Mode_common(parent, co),
    ui(new Ui::Mode_run)
{
    ui->setupUi(this);
    g_mode_name = "Mode run";
    g_control_enable = false;

    g_controller_timer = new QTimer(this);
    connect(g_controller_timer, SIGNAL(timeout()), this, SLOT(remote_controll_cmd()));
    g_logging = false;

    g_3d_scatter = new Q3DScatter();
    g_input_handler = new Q3DInputHandler();
    g_3d_container = QWidget::createWindowContainer(g_3d_scatter);
    g_3d_scatter->setActiveInputHandler(g_input_handler);

    g_3d_scatter->scene()->activeCamera()->setZoomLevel(150.0f);
    g_3d_scatter->scene()->activeCamera()->setCameraPreset( Q3DCamera::CameraPresetBehindBelow);

    QScatter3DSeries *series = new QScatter3DSeries;
    QScatterDataArray data;
    data << QVector3D(0.0f, 0.0f, 3.0f) << QVector3D(13.2f, 0.0f, 3.0f) << QVector3D(13.2f, 3.6f, 3.0f) << QVector3D(0.0f, 3.6f, 3.0f);
    series->setItemSize(0.2);
    series->dataProxy()->addItems(data);
    g_3d_scatter->addSeries(series);

    data.clear();
    series = new QScatter3DSeries;
    data << QVector3D(0.0f, 0.0f, 0.0f) << QVector3D(13.2f, 0.0f, 0.0f) << QVector3D(13.2f, 3.6f, 0.0f) << QVector3D(0.0f, 3.6f, 0.0f);
    series->dataProxy()->addItems(data);
    series->setBaseColor(QColor(0,255,0));
    series->setItemSize(0.01);
    g_3d_scatter->addSeries(series);

    g_plot_3d = new QPlot3D();
    QCurve3D *skeleton = new QCurve3D();
    skeleton->addData(0,0,0);
    skeleton->addData(QVector3D(13.2,0,0));
    skeleton->addData(QVector3D(13.2,3.6,0));
    skeleton->addData(QVector3D(0,3.6,0));
    skeleton->addData(QVector3D(0,0,3));
    skeleton->addData(QVector3D(13.2,0,3));
    skeleton->addData(QVector3D(13.2,3.6,3));
    skeleton->addData(QVector3D(0,3.6,3));
    skeleton->setColor(Qt::green);
    g_plot_3d->addCurve(skeleton);

    g_qs3s_trajectory = new QScatter3DSeries();
    g_qs3s_trajectory->setItemSize(0.02);
    g_qs3s_trajectory->setBaseColor(QColor(0,0,255));
    g_3d_scatter->addSeries(g_qs3s_trajectory);

    g_state = new QScatter3DSeries();
    g_state->setItemSize(0.1);
    g_state->setBaseColor(QColor(255,0,0));
    g_3d_scatter->addSeries(g_state);

    g_ekf_initing = false;
    g_ekf_running = false;

    QSettings settings;
    ui->cb_ekf_mode->setCurrentIndex(settings.value("ekf_mode", 0).toInt());
    g_ekf_mode = (ekf_mode_t)ui->cb_ekf_mode->currentIndex();

    g_qs3s_ref_trajectory = new QScatter3DSeries();
    g_qs3s_ref_trajectory->setItemSize(0.02);
    g_qs3s_ref_trajectory->setBaseColor(QColor(0,255,255));
    g_3d_scatter->addSeries(g_qs3s_ref_trajectory);

    g_qs3s_dwa_trajectory = new QScatter3DSeries();
    g_qs3s_dwa_trajectory->setItemSize(0.035);
    g_qs3s_dwa_trajectory->setBaseColor(QColor(0,255,0));
    g_3d_scatter->addSeries(g_qs3s_dwa_trajectory);

    g_qs3s_dwa_ref_trajectory = new QScatter3DSeries();
    g_qs3s_dwa_ref_trajectory->setItemSize(0.035);
    g_qs3s_dwa_ref_trajectory->setBaseColor(QColor(255,0,255));
    g_3d_scatter->addSeries(g_qs3s_dwa_ref_trajectory);
}

Mode_run::~Mode_run()
{
    delete g_controller_timer;
    delete ui;
}

void Mode_run::select(){
   clear_drawing_area();
   g_co->drawing_area->addWidget(g_3d_container);
   // g_co->drawing_area->addWidget(g_plot_3d);
}

void Mode_run::mav_recv(mavlink_message_t *msg){
    switch(msg->msgid) {
    case MAVLINK_MSG_ID_EVT_RPY:
        mavlink_evt_rpy_t evt_rpy;
        mavlink_msg_evt_rpy_decode(msg, &evt_rpy);
        ui->txtBoxRoll->setText(QString::number(static_cast<double>(evt_rpy.roll)));
        ui->txtBoxPitch->setText(QString::number(static_cast<double>(evt_rpy.pitch)));
        ui->txtBoxYaw->setText(QString::number(static_cast<double>(evt_rpy.yaw)));
        break;
    case MAVLINK_MSG_ID_EVT_SENSOR:
        mavlink_evt_sensor_t sensor_status;
        mavlink_msg_evt_sensor_decode(msg,&sensor_status);
        if(sensor_status.imu_status == SENSOR_IMU_OK){
            show_status("IMU OK", 1000);
        }
        else{
            show_status("IMU ERROR", 1000);
        }
        break;
    case MAVLINK_MSG_ID_EVT_TILT_CAL:
        mavlink_evt_tilt_raw_t tilt_msg;
        mavlink_msg_evt_tilt_raw_decode(msg,&tilt_msg);
        ui->tb_tilt_cal->setText(QString::number(tilt_msg.tilt));
        break;
    case MAVLINK_MSG_ID_CONTROL:
    {
        mavlink_control_t control;
        mavlink_msg_control_decode(msg, &control);
        QString line;
        line = "C " + QString::number(control.left) + " " + QString::number(control.right) + "\n";
        ui->pteControl->appendHtml(line);
        if(g_logging) g_file_control_measurement.write(line.toStdString().c_str());

        if(g_ekf_running == true){

            ekf_control_t c;

            float l = -control.left;
            float r = -control.right;
            c.l = l/g_ekf_params.pule_per_revolution*(M_PI*g_ekf_params.wheel_diameter);
            c.r = r/g_ekf_params.pule_per_revolution*(M_PI*g_ekf_params.wheel_diameter);
            ekf_predict(&g_ekf, &c);

            QScatterDataArray data;
            data << QVector3D(g_ekf.x, g_ekf.y, 0.0f);
            g_state->dataProxy()->deleteLater();
            g_state->setDataProxy(new QScatterDataProxy());
            g_state->dataProxy()->addItems(data);
            g_qs3s_trajectory->dataProxy()->addItems(data);
        }
    }
        break;
    case MAVLINK_MSG_ID_MEASUREMENT:
        mavlink_measurement_t measurement;
        mavlink_msg_measurement_decode(msg, &measurement);
        QString line;
        line =  "M " + QString::number(measurement.x) + " " + QString::number(measurement.y) + " " + QString::number(measurement.z)
                + " " + QString::number(measurement.r) + " " + QString::number(measurement.yaw) + "\n";
        ui->pteMeasurement->appendHtml(line);
        if(g_logging) g_file_control_measurement.write(line.toStdString().c_str());
        if(g_ekf_mode == REAL_TIME){
            if(g_ekf_initing){
                sphere_t sphere = {
                    .x = measurement.x,
                    .y = measurement.y,
                    .z = 3,
                    .r = measurement.r,
                };
                g_spheres.append(sphere);
                g_yaw = -measurement.yaw/180.0f*M_PI;
                if(g_spheres.size() >= 3){
                    sphere_t spheres[3] = {g_spheres[0], g_spheres[1], g_spheres[2]};
                    g_spheres.clear();
                    trilateration_result_t trilateration_result;
                    trilaterate(spheres, &trilateration_result);
                    ekf_reset(trilateration_result.PA.x, trilateration_result.PA.y, g_yaw - (-0.52359877559));
                    g_ekf_initing = false;
                    ui->btn_init_ekf->setText("Init EKF");
                }
            }
            else if(g_ekf_running){
                ekf_measurement_t m;
                m.rx = measurement.x;
                m.ry = measurement.y;
                m.range = measurement.r;
                m.range = sqrt(m.range*m.range-3.0f*3.0f);
                if(isnanf(m.range)) return;
                m.yaw = - (measurement.yaw/180.0f*M_PI - (-0.52359877559));
                ekf_correct(&g_ekf, &m);

                qDebug() << g_ekf.x << " " << g_ekf.y << " " << g_ekf.theta;

                QScatterDataArray data;
                data << QVector3D(g_ekf.x, g_ekf.y, 0.0f);
                g_state->dataProxy()->deleteLater();
                g_state->setDataProxy(new QScatterDataProxy());
                g_state->dataProxy()->addItems(data);
                g_qs3s_trajectory->dataProxy()->addItems(data);
            }
        }
    }
}

void Mode_run::remote_controll_cmd(){
    mavlink_message_t msg;
    uint8_t mav_send_buf[255];
    float VX = ui->txtb_pidt_vx->text().toFloat();
    float OMEGA = ui->txtb_pidt_w->text().toFloat();
    mavlink_msg_cmd_velocity_pack(0,0,&msg,VX,OMEGA);
    uint16_t len = mavlink_msg_to_send_buffer(mav_send_buf, &msg);
    emit mav_send(QByteArray::fromRawData(reinterpret_cast<char*>(mav_send_buf),len));
}

void Mode_run::on_btn_control_enable_clicked()
{
    if(g_control_enable == false){
        g_control_enable=true;
        ui->btn_control_enable->setText("Enabled");
        g_controller_timer->start(100);
    }
    else{
        g_control_enable = false;
        ui->btn_control_enable->setText("Disabled");
        g_controller_timer->stop();
    }
}

void Mode_run::on_btn_change_mode_run_clicked()
{
    emit mode_change(MODE_RUN);
}

void Mode_run::update_joystick(int axis, double value){
    switch (axis){
    case 0:
        ui->txtb_pidt_w->setText(QString::number(value));
        break;
    case 1:
        ui->txtb_pidt_vx->setText(QString::number(value));
    }
}

void Mode_run::on_btn_log_clicked()
{
    if(g_logging){
        g_logging = false;
        ui->btn_log->setText("Log");
        if(g_file_control_measurement.isOpen()){
            g_file_control_measurement.close();
        }
    }
    else{
        g_file_control_measurement.setFileName("control_measurement.txt");
        if(g_file_control_measurement.open(QIODevice::WriteOnly | QIODevice::Text)){
            g_logging = true;
            ui->btn_log->setText("Logging");
            ui->pteMeasurement->clear();
            ui->pteControl->clear();
        }
    }
}

void Mode_run::on_btn_cm_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Open file");
    ui->tb_cm->setText(file_name);
}

void Mode_run::on_btn_run_ekf_clicked()
{
    if(g_ekf_mode == REAL_TIME || g_ekf_mode == RT_PREDICT){
        if(g_ekf_running == true){
            g_ekf_running = false;
            ui->btn_run_ekf->setText("Run EKF");
        }else{
            g_ekf_running = true;
            ui->btn_run_ekf->setText("Running");
        }
    }
    else if(g_ekf_mode == FROM_FILE){
        QFile in(ui->tb_cm->text());
        QFile out("correction.txt");
        if (!in.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        if (!out.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QScatterDataArray data;
        g_trajectory.clear();

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList sl = line.split(" ");
            if(sl.at(0) == "C"){
                ekf_control_t c;
                float l = -sl.at(1).toFloat();
                float r = -sl.at(2).toFloat();
                c.l = l/g_ekf_params.pule_per_revolution*(M_PI*g_ekf_params.wheel_diameter);
                c.r = r/g_ekf_params.pule_per_revolution*(M_PI*g_ekf_params.wheel_diameter);
                ekf_predict(&g_ekf, &c);
                data << QVector3D(g_ekf.x, g_ekf.y, 0.0f);
                ekf_state_t ekf_state = {
                    .x = g_ekf.x,
                    .y = g_ekf.y,
                    .w = g_ekf.theta,
                };
                g_trajectory.append(ekf_state);
            }
            else if (sl.at(0) == "M"){
                ekf_measurement_t m;
                m.rx = sl.at(1).toFloat();
                m.ry = sl.at(2).toFloat();
                if(fabs(m.rx) < 1 && fabs(m.ry) < 1) continue;
                m.range = sl.at(4).toFloat();
                m.range = sqrt(m.range*m.range-3.0f*3.0f);
                m.yaw = sl.at(5).toFloat()/180*M_PI - (-0.52359877559);
                ekf_correct(&g_ekf, &m);
                QTextStream stream(&out);
                stream << "F " << g_ekf.x*300+500 << " " << g_ekf.y*300+3000 << " " << g_ekf.theta << endl;
                data << QVector3D(g_ekf.x, g_ekf.y, 0.0f);
                ekf_state_t ekf_state = {
                    .x = g_ekf.x,
                    .y = g_ekf.y,
                    .w = g_ekf.theta,
                };
                g_trajectory.append(ekf_state);
            }
        }

        g_qs3s_trajectory->dataProxy()->deleteLater();
        g_qs3s_trajectory->setDataProxy(new QScatterDataProxy());
        g_qs3s_trajectory->dataProxy()->addItems(data);

        ui->hs_ekf_state->setMaximum(g_trajectory.size()-1);
        ui->lb_total_state->setText(QString::number(g_trajectory.size()));

        in.close();
        out.close();
    }
    else if(g_ekf_mode == FILE_PREDICT){
        QFile in(ui->tb_cm->text());
        QFile out("correction.txt");
        if (!in.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
        if (!out.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QScatterDataArray data;
        g_trajectory.clear();

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList sl = line.split(" ");
            if(sl.at(0) == "C"){
                ekf_control_t c;
                float l = -sl.at(1).toFloat();
                float r = -sl.at(2).toFloat();
                c.l = l/g_ekf_params.pule_per_revolution*(M_PI*g_ekf_params.wheel_diameter);
                c.r = r/g_ekf_params.pule_per_revolution*(M_PI*g_ekf_params.wheel_diameter);
                ekf_predict(&g_ekf, &c);
                data << QVector3D(g_ekf.x, g_ekf.y, 0.0f);
                ekf_state_t ekf_state = {
                    .x = g_ekf.x,
                    .y = g_ekf.y,
                    .w = g_ekf.theta,
                };
                g_trajectory.append(ekf_state);
            }
        }

        g_qs3s_trajectory->dataProxy()->deleteLater();
        g_qs3s_trajectory->setDataProxy(new QScatterDataProxy());
        g_qs3s_trajectory->dataProxy()->addItems(data);

        ui->hs_ekf_state->setMaximum(g_trajectory.size()-1);
        ui->lb_total_state->setText(QString::number(g_trajectory.size()));

        in.close();
        out.close();
    }
}

void Mode_run::on_hs_ekf_state_sliderMoved(int position)
{
    ui->lb_curren_state->setText(QString::number(position));
    if(g_trajectory.size() == 0) return;

    QScatterDataArray data;
    data << QVector3D(g_trajectory[position].x, g_trajectory[position].y, 0.0f);
    g_state->dataProxy()->deleteLater();
    g_state->setDataProxy(new QScatterDataProxy());
    g_state->dataProxy()->addItems(data);
}

void Mode_run::on_btn_init_ekf_clicked()
{

    g_qs3s_trajectory->dataProxy()->deleteLater();
    g_qs3s_trajectory->setDataProxy(new QScatterDataProxy());

    if(g_ekf_mode == REAL_TIME){
        if(g_ekf_initing){
            g_ekf_initing = false;
            ui->btn_init_ekf->setText("Init EKF");
        }else{
            g_ekf_initing = true;
            ui->btn_init_ekf->setText("Initializing");
        }
    }
    else if(g_ekf_mode == FROM_FILE){
        QFile in(ui->tb_cm->text());
        if (!in.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        sphere_t spheres[3];
        uint8_t sphere_idx = 0;
        float yaw = 0;
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList sl = line.split(" ");
            if(sl.at(0) == "M"){
                qDebug() << sl << endl;
                spheres[sphere_idx].x = sl.at(1).toFloat();
                spheres[sphere_idx].y = sl.at(2).toFloat();
                spheres[sphere_idx].z = 3;
                spheres[sphere_idx].r = sl.at(4).toFloat();
                yaw = sl.at(5).toFloat()/180*M_PI;
                sphere_idx++;
                if(sphere_idx == 3) break;
            }
        }

        trilateration_result_t trilateration_result;
        trilaterate(spheres, &trilateration_result);
        ekf_reset(trilateration_result.PA.x, trilateration_result.PA.y, yaw - (-0.52359877559));
    }
    else if(g_ekf_mode == RT_PREDICT || g_ekf_mode == FILE_PREDICT){
        ekf_reset(ui->tb_initial_state_x->text().toFloat(), ui->tb_initial_state_y->text().toFloat(), ui->tb_initial_state_w->text().toFloat());
    }
}

void Mode_run::on_cb_ekf_mode_currentIndexChanged(int index)
{
    QSettings setting;
    setting.setValue("ekf_mode", index);
    g_ekf_mode = (ekf_mode_t)index;
}

void Mode_run::ekf_reset(float x, float y, float w){
    ui->tb_initial_state_x->setText(QString::number(x));
    ui->tb_initial_state_y->setText(QString::number(y));
    ui->tb_initial_state_w->setText(QString::number(w));

    g_ekf_params.robot_width = ui->tb_pm_w->text().toFloat();
    g_ekf_params.control_motion_factor = ui->tb_pm_cmf->text().toFloat();
    g_ekf_params.control_turn_factor = ui->tb_pm_ctf->text().toFloat();
    g_ekf_params.tag_cart_x = ui->tb_pm_tcx->text().toFloat();
    g_ekf_params.tag_cart_y = ui->tb_pm_tcy->text().toFloat();
    g_ekf_params.measurement_distance_stddev = ui->tb_pm_mds->text().toFloat();
    g_ekf_params.measurement_angle_stddev = ui->tb_pm_mas->text().toFloat()/180*M_PI;

    g_ekf_params.pule_per_revolution = ui->tb_pm_ppr->text().toFloat();
    g_ekf_params.wheel_diameter = ui->tb_pm_wd->text().toFloat();


    g_ekf.x = x;
    g_ekf.y = y;
    g_ekf.theta = w;

    g_ekf.cov[0][1] = g_ekf.cov[0][2] = 0.0f;
    g_ekf.cov[1][0] = g_ekf.cov[1][2] = 0.0f;
    g_ekf.cov[2][0] = g_ekf.cov[2][1] = 0.0f;

    g_ekf.cov[0][0] = 0.1;
    g_ekf.cov[1][1] = 0.1;
    g_ekf.cov[2][2] = (50.0 / 180.0 * M_PI);

    g_ekf.cov[0][0] = g_ekf.cov[0][0]*g_ekf.cov[0][0];
    g_ekf.cov[1][1] = g_ekf.cov[1][1]*g_ekf.cov[1][1];
    g_ekf.cov[2][2] = g_ekf.cov[2][2]*g_ekf.cov[2][2];

    ekf_init(&g_ekf, &g_ekf_params);

    QString str;
    QTextStream tr(&str);
    tr << "Intial state: " << g_ekf.x << " " << g_ekf.y << " " << g_ekf.theta << " ";
    show_status(str, 1000);
}

void Mode_run::on_btn_trajectory_gen_clicked()
{
    if(ui->cb_trajectory->currentText() == "Lemniscate"){
        float cx = ui->tb_trajectory_params_0->text().toFloat();
        float cy = ui->tb_trajectory_params_1->text().toFloat();
        float a = ui->tb_trajectory_params_2->text().toFloat();
        float size = ui->tb_trajectory_params_3->text().toFloat();
        g_ref_trajectory_2d =  lemniscate_2d(cx, cy, a, size);

        QScatterDataArray data = to_scatter_data_array(g_ref_trajectory_2d);
        g_qs3s_ref_trajectory->dataProxy()->deleteLater();
        g_qs3s_ref_trajectory->setDataProxy(new QScatterDataProxy());
        g_qs3s_ref_trajectory->dataProxy()->addItems(data);
    }
}

void Mode_run::on_btn_follow_clicked()
{
    if(g_ref_trajectory_2d.size() == 0) return;

    float min_dist = std::numeric_limits<float>::max();
    int min_dist_idx = 0;
    for (int i=0; i<g_ref_trajectory_2d.size(); i++){
        float dx = g_ekf.x -  g_ref_trajectory_2d[i].x;
        float dy = g_ekf.y - g_ref_trajectory_2d[i].y;
        float dist = dx*dx + dy*dy;
        if(dist < min_dist){
            min_dist = dist;
            min_dist_idx = i;
        }
    }

    QVector<trajectory_point_2d_t> traj;
    for(int i=min_dist_idx; i<min_dist_idx+DWA_SIM_SIZE; i++){
        int idx = i>=g_ref_trajectory_2d.size() ? i-g_ref_trajectory_2d.size() : i;
        traj.append(g_ref_trajectory_2d[idx]);
    }
    QScatterDataArray data;
    data = to_scatter_data_array(traj);
    g_qs3s_dwa_ref_trajectory->dataProxy()->deleteLater();
    g_qs3s_dwa_ref_trajectory->setDataProxy(new QScatterDataProxy());
    g_qs3s_dwa_ref_trajectory->dataProxy()->addItems(data);

    dwa_t dwa;
    dwa_params_t params;
    params.v_max = ui->tb_dwa_v->text().toFloat();
    params.v_min = -params.v_max;
    params.w_max = ui->tb_dwa_w->text().toFloat();
    params.w_min = -params.w_max;
    dwa_state_t state;
    state.x = g_ekf.x;
    state.y = g_ekf.y;
    state.w = g_ekf.theta;

    dwa_init(&dwa, &params);
    dwa_gen(&dwa,&state);
    dwa_score(&dwa,traj);

    data = to_scatter_data_array(&dwa);
    g_qs3s_dwa_trajectory->dataProxy()->deleteLater();
    g_qs3s_dwa_trajectory->setDataProxy(new QScatterDataProxy());
    g_qs3s_dwa_trajectory->dataProxy()->addItems(data);
}
