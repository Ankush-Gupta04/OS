import matplotlib.pyplot as plt
import numpy as np

rr = open("rr_reading.txt","r")
othr = open("othr_reading.txt","r")
fifo = open("fifo_reading.txt","r")

x = [ x for x in rr.read().split("\n")]

x = x[0:10]

rr_l = [float(i) for i in x]

x = [ x for x in othr.read().split("\n")]

x = x[0:10]

othr_l = [float(i) for i in x]

x = [x for x in fifo.read().split("\n")]

x = x[0:10]

fifo_l = [float(i) for i in x]

othr_p = [i for i in range(0,10)]

rr_p = [ 46 - i for i in range(0,10)]

fifo_p = [45 - i for i in range(0,10)]

plt.bar(othr_p,othr_l, color='black', width=0.2)

# naming the x axis
plt.xlabel('nice value')
# naming the y axis
plt.ylabel('time')

# giving a title to my graph
plt.title('other ')

# function to show the plot
plt.show()


plt.bar(rr_p,rr_l, color='black', width=0.2)

# naming the x axis
plt.xlabel('nice value')
# naming the y axis
plt.ylabel('time')

# giving a title to my graph
plt.title('rr')

# function to show the plot
plt.show()

plt.bar(fifo_p,fifo_l, color='black', width=0.2)

# naming the x axis
plt.xlabel('nice value')
# naming the y axis
plt.ylabel('time')

# giving a title to my graph
plt.title('other ')

# function to show the plot
plt.show()

