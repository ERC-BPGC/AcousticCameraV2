
import numpy as np
import serial
from serial import Serial
import matplotlib.pyplot as plt
import time
from tqdm import tqdm

try:
	port = Serial(port="COM3", baudrate=115200, bytesize=8, timeout=2, stopbits=serial.STOPBITS_ONE)
except serial.SerialException:
	print('Error initialising port!')
	exit()

num_samples = 6000  # number of samples to record
num_mics = 4

finaldata = np.zeros((num_samples, num_mics), dtype=np.int16)
rawdata = None

print('Starting recording in 2 seconds...')
time.sleep(1)
print('Starting in 1...')
time.sleep(1)


for i in tqdm(range(num_samples)):
	try:
		rawdata = port.readline().strip().decode('utf8')
		rawdata = [int(d) for d in rawdata.split(',')]
		finaldata[i] = np.array(rawdata)
	except:
		print(f'Error reading line number {i}, skipping.')

finaldata = finaldata.T

fig, axs = plt.subplots(num_mics)
for m in range(num_mics):
	axs[m].plot(finaldata[m], alpha=0.8)

# plt.legend([str(m) for m in range(num_mics)])
plt.show()
