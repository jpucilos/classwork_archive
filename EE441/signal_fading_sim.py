import math
import numpy
import matplotlib.pyplot as plt


def rayleigh_fade(f0, v):
	fs = 20
	n = 9
	v = v/2.23694
	wavelength = 300.0 / f0
	t = []
	r= []
	for k in range(1, int(100.0*fs / wavelength / v) ):
		t.append(k * wavelength / fs * v)
		x = 0
		y = 0
		for i in range(1, 10):
			ri = numpy.random.normal(0,1,1)
			si = numpy.random.normal(0,1,1)
			phi = 2 * math.pi * i / n
			x += ri * math.cos(k*2*math.pi / fs * math.cos(phi)) - si * math.sin(k*2*math.pi / fs * math.cos(phi))
			y += si * math.cos(k*2*math.pi / fs * math.cos(phi)) - ri * math.sin(k*2*math.pi / fs * math.cos(phi))

		r.append(math.sqrt(x*x + y*y))
	plt.plot(t, r)

	plt.title("Rayleigh Fading Signal")
	plt.xlabel("Time (ms)")
	plt.ylabel("Signal Strength (dB)")
	plt.yscale('log')
	plt.grid(True)
	plt.show()
	plt.gcf().clear()
	return
	
rayleigh_fade(800,25)
rayleigh_fade(800,55)
rayleigh_fade(1900,25)
rayleigh_fade(1900,55)