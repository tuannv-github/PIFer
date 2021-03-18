input = open("../sim/reference.txt", 'r')
output = open("reference.txt",'w')
for line in input.readlines():
    x, y, w = line.split(" ")
    x = float(x)
    y = float(y)
    w = float(w)
    x=(int)(x*1000) + 2000
    y=(int)(y*1000) + 2000
    w=(int)(w)
    print((x,y,w))
    output.write("P " + str(w) + " " + str(x) + " " + str(y) + "\r\n")