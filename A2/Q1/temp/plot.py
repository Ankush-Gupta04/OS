import matplotlib.pyplot as plt
import numpy as np

r = open("readings.txt","r")

x = [ x for x in r.read().split("\n")]

x = x[0:3]

r_l = [float(i) for i in x]

r_p = ["other","fifo","rr"]


plt.bar(r_p,r_l, color='black', width=0.2)

# naming the x axis
plt.xlabel('nice value')
# naming the y axis
plt.ylabel('time')

# giving a title to my graph
plt.title('other ')

# function to show the plot
plt.show()

