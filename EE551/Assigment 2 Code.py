import matplotlib.pyplot as plot
import numpy as nump

#Write just the numbers to a new file
F = open('24hourscopy.txt', 'r')
S = open('NumbersOnly.txt', 'w')
for line in F:
	string = line
	lst = string.split()
	newstring = lst[7]
	num = newstring.replace("time=","")
	S.write( num + '\n')
F.close()
S.close()

#Use matplotlib and numpy to plot CDF
data = nump.loadtxt('NumbersOnly.txt')
sorted_data = nump.sort(data)
yvals= nump.arange(len(sorted_data))/float(len(sorted_data))
plot.plot(sorted_data, yvals)
plot.show()
