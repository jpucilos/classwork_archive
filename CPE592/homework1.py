# CPE592 - Homework 1
# Author: Joseph Puciloski
#
# How to use from command line:
# python homework1.py <payload> <carrier_file_name> <key>

from PIL import Image
import sys

def set_bit_lsb(old_byte, new_bit):
	b = list(bin(old_byte))
	b[-1] = new_bit
	return int(''.join(b),2)

def encode_image_lsb(img):
	lsb = img.copy()
	bitstream = iter(''.join(format(x, 'b') for x in bytearray(message, 'utf8')))
	try:
		for a in range(key, img.size[0] * img.size[1]):
			
			i = int(a / img.size[0])
			j = a % img.size[0]
			
			r,g,b = img.getpixel((j,i))
			
			rb = next(bitstream)
			r = set_bit_lsb(r, rb)
			
			gb = next(bitstream)
			g = set_bit_lsb(g, gb)
			
			bb = next(bitstream)
			b = set_bit_lsb(b, bb)
			
			lsb.putpixel((j,i),(r,g,b))
	except:
		print("Finished encoding LSB")
	
	lsb.save("lsb.jpg", "jpeg")
	return

def set_bit_msb(old_byte, new_bit):
	b = list(format(old_byte, 'b'))
	b[0] = new_bit
	try:
		b = int(''.join(b),2)
		return b
	except:
		return old_byte

def encode_image_msb(img):
	msb = img.copy()
	bitstream = iter(' '.join(format(x, 'b') for x in bytearray(message, 'utf8')))
	try:
		for a in range(key, img.size[0] * img.size[1]):
			
			i = int(a / img.size[0])
			j = a % img.size[0]

			r,g,b = img.getpixel((j,i))
			
			rb = next(bitstream)
			r = set_bit_msb(r, rb)
			
			gb = next(bitstream)
			g = set_bit_msb(g, gb)
			
			bb = next(bitstream)
			b = set_bit_msb(b, bb)
			
			msb.putpixel((j,i),(r,g,b))
	except Exception as e:
		print("Finished encoding MSB")
	
	msb.save("msb.jpg", "jpeg")
	return

message = sys.argv[1]
img = Image.open(sys.argv[2])
key = sum(bytearray(sys.argv[3], "utf8"))

if key + len(message) < img.size[1] * img.size[0]:
	pixels = img.load()
	encode_image_lsb(img)
	encode_image_msb(img)
	
else:
	print("Invalid key and message")




