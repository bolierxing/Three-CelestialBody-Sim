from tkinter import*
from time import sleep

def main():
    
    f1 = open("data1.dat")
    f2 = open("data2.dat")
    f3 = open("data3.dat")
    f = open("scale.dat")
    s = f.read(1)
    
    xmin = ""
    while (s[0] >= "0")and(s[0] <= "9") or (s[0] == ".") or (s[0] == "-"):
        xmin = xmin + s
        s = f.read(1)
    xminn = float(xmin)
    
    while ((s[0] < "0")or(s[0] > "9")) and (s[0] != ".") and (s[0] != "-"):
        s = f.read(1)
    ymin = ""
    while (s[0] >= "0")and(s[0] <= "9") or (s[0] == ".") or (s[0] == "-"):
        ymin = ymin + s
        s = f.read(1)
    s = f.readline()
    s = f.read(1)
    xmax = ""
    while (s[0] >= "0")and(s[0] <= "9") or (s[0] == ".") or (s[0] == "-"):
        xmax = xmax + s
        s = f.read(1)
    while ((s[0] < "0")or(s[0] > "9")) and (s[0] != ".") and (s[0] != "-"):
        s = f.read(1)
    ymax = ""
    while (s[0] >= "0")and(s[0] <= "9") or (s[0] == ".") or (s[0] == "-"):
        ymax = ymax + s
        s = f.read(1)
    s = f.readline()
    xminn = float(xmin)
    yminn = float(ymin)
    xmaxn = float(xmax)
    ymaxn = float(ymax)

    root = Tk()
    c = Canvas(root, width = 300 + 10,height = 10 + 300 * (ymaxn - yminn) / (xmaxn - xminn),bg = 'white')
    c.pack()
    s = f1.read(1)
    
    x1 = 0.0
    y1 = 0.0
    x2 = 0.0
    y2 = 0.0
    x3 = 0.0
    y3 = 0.0
    lx1 = 0.0
    ly1 = 0.0
    lx2 = 0.0
    ly2 = 0.0
    lx3 = 0.0
    ly3 = 0.0
    i = 0
    while s != "":
        xs = ""
        while (s[0] >= "0")and(s[0] <= "9") or (s[0] == ".") or (s[0] == "-"):
            xs = xs + s
            s = f1.read(1)
            
        while ((s[0] < "0")or(s[0] > "9")) and (s[0] != ".") and (s[0] != "-"):
            s = f1.read(1)
            
        ys = ""
        while (s[0] >= "0")and(s[0] <= "9") or (s[0] == ".") or (s[0] == "-"):
            ys = ys + s
            s = f1.read(1)
        s = f1.readline()
        x1 = float (xs)
        y1 = float (ys)

        s = f2.read(1)
        xs = ""
        while (s[0] >= "0")and(s[0] <= "9") or (s[0] == ".") or (s[0] == "-"):
            xs = xs + s
            s = f2.read(1)
            
        while ((s[0] < "0")or(s[0] > "9")) and (s[0] != ".") and (s[0] != "-"):
            s = f2.read(1)
            
        ys = ""
        while (s[0] >= "0")and(s[0] <= "9") or (s[0] == ".") or (s[0] == "-"):
            ys = ys + s
            s = f2.read(1)
        s = f2.readline()
        x2 = float (xs)
        y2 = float (ys)

        s = f3.read(1)
        xs = ""
        while (s[0] >= "0")and(s[0] <= "9") or (s[0] == ".") or (s[0] == "-"):
            xs = xs + s
            s = f3.read(1)
            
        while ((s[0] < "0")or(s[0] > "9")) and (s[0] != ".") and (s[0] != "-"):
            s = f3.read(1)
            
        ys = ""
        while (s[0] >= "0")and(s[0] <= "9") or (s[0] == ".") or (s[0] == "-"):
            ys = ys + s
            s = f3.read(1)
        s = f3.readline()
        x3 = float (xs)
        y3 = float (ys)
        i = i + 1
        
        times = 300 / (xmaxn-xminn)
     
        if i == 1:
            star1 = c.create_oval((x1 - xminn) * times-0.2,(y1 - yminn) * times-0.2,(x1 - xminn) * times + 9.8,(y1 - yminn) * times + 9.8,fill = 'red')
            star2 = c.create_oval((x2 - xminn) * times-0.2,(y2 - yminn) * times-0.2,(x2 - xminn) * times + 9.8,(y2 - yminn) * times + 9.8,fill = 'blue')
            star3 = c.create_oval((x3 - xminn) * times-0.2,(y3 - yminn) * times-0.2,(x3 - xminn) * times + 9.8,(y3 - yminn) * times + 9.8,fill = 'green')
            c.update()
        else:
            ex1 = x1 * times - lx1 * times
            ex2 = x2 * times - lx2 * times
            ex3 = x3 * times - lx3 * times
            ey1 = y1 * times - ly1 * times
            ey2 = y2 * times - ly2 * times
            ey3 = y3 * times - ly3 * times
            
            c.move(star1,ex1,ey1)
            c.move(star2,ex2,ey2)
            c.move(star3,ex3,ey3)
            c.update()
        
        lx1 = x1
        lx2 = x2
        lx3 = x3
        ly1 = y1
        ly2 = y2
        ly3 = y3
        s = f1.read(1)
    

main()
