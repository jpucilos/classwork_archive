# CPE440 - Homework 5
# Author: Joseph Puciloski
#
import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv('weatherAUS.csv')

target = df['RainTomorrow']

x = data['Humidity3pm']
y = data['Pressure3pm']

rain_x = []
rain_y = []

no_rain_x = []
no_rain_y = []


for i in range(0, len(x)):
	if target[i] == 'Yes':
		rain_x.append(x[i])
		rain_y.append(y[i])
	else:
		no_rain_x.append(x[i])
		no_rain_y.append(y[i])
		
