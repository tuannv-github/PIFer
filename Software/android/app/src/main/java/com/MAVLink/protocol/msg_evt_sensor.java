/* AUTO-GENERATED FILE.  DO NOT MODIFY.
 *
 * This class was automatically generated by the
 * java mavlink generator tool. It should not be modified by hand.
 */

// MESSAGE EVT_SENSOR PACKING
package com.MAVLink.protocol;
import com.MAVLink.MAVLinkPacket;
import com.MAVLink.Messages.MAVLinkMessage;
import com.MAVLink.Messages.MAVLinkPayload;
        
/**
* Report sensor status. No need a respond message for confimation
*/
public class msg_evt_sensor extends MAVLinkMessage{

    public static final int MAVLINK_MSG_ID_EVT_SENSOR = 6;
    public static final int MAVLINK_MSG_LENGTH = 1;
    private static final long serialVersionUID = MAVLINK_MSG_ID_EVT_SENSOR;


      
    /**
    * IMU status
    */
    public byte imu_status;
    

    /**
    * Generates the payload for a mavlink message for a message of this type
    * @return
    */
    public MAVLinkPacket pack(){
        MAVLinkPacket packet = new MAVLinkPacket(MAVLINK_MSG_LENGTH);
        packet.sysid = 255;
        packet.compid = 190;
        packet.msgid = MAVLINK_MSG_ID_EVT_SENSOR;
              
        packet.payload.putByte(imu_status);
        
        return packet;
    }

    /**
    * Decode a evt_sensor message into this class fields
    *
    * @param payload The message to decode
    */
    public void unpack(MAVLinkPayload payload) {
        payload.resetIndex();
              
        this.imu_status = payload.getByte();
        
    }

    /**
    * Constructor for a new message, just initializes the msgid
    */
    public msg_evt_sensor(){
        msgid = MAVLINK_MSG_ID_EVT_SENSOR;
    }

    /**
    * Constructor for a new message, initializes the message with the payload
    * from a mavlink packet
    *
    */
    public msg_evt_sensor(MAVLinkPacket mavLinkPacket){
        this.sysid = mavLinkPacket.sysid;
        this.compid = mavLinkPacket.compid;
        this.msgid = MAVLINK_MSG_ID_EVT_SENSOR;
        unpack(mavLinkPacket.payload);        
    }

      
    /**
    * Returns a string with the MSG name and data
    */
    public String toString(){
        return "MAVLINK_MSG_ID_EVT_SENSOR - sysid:"+sysid+" compid:"+compid+" imu_status:"+imu_status+"";
    }
}
        