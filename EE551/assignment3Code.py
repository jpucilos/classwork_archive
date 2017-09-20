import matplotlib.pyplot as plot
import numpy as nump

#Write just the numbers to a new file
F = open('dumpfile.txt', 'r')
S = open('DelayValues.txt', 'w')
for line in F:
	string = line
	lst = string.split()
	if (lst[0] == "15"):
		newstring = lst[len(lst)-2]
		if (newstring != "ms" and newstring != "*"):
			S.write( newstring + '\n')
F.close()
S.close()

#Use matplotlib and numpy to plot CDF
data = nump.loadtxt('DelayValues.txt')
sorted_data = nump.sort(data)
yvals= nump.arange(len(sorted_data))/float(len(sorted_data))
plot.title("Trace Route CDF www.prodisney.ru")
plot.xlabel("Delay Time (Milliseconds)")
plot.ylabel("Probability")
plot.plot(sorted_data, yvals)
plot.show()
