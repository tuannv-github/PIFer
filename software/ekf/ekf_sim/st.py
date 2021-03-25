f = open("tmp.txt")
out = open("out.txt",'w')
for line in f.readlines():
    l = line.split(" ")
    if l[0] == 'C':
        out.write(line)
