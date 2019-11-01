#Homework 3 - Joseph Puciloski
#Simple RSA Encryption Implementation
import math

def gcd(x, y):
	a = max(x, y)
	b = min(x, y)
	k = 1
	while k != 0:
		k = a - b * math.floor(a/b)
		if k == 0:
			return b
		else:
			a = b
			b = k
	return b
	
#User input for p and q
p = int(input('Please enter a prime number for p:'))
q = int(input('Please enter a prime number for q:'))

#Calculate n and (p-1)*(q-1)
n = p * q
v = (p-1)*(q-1)

#Determine e (simple method) (manual input)
e = 3
while gcd(v,e) != 1:
	e = e + 1
	
print('Public key: {' + str(e) + ',' + str(n) + '}')

#Calculate d (simple method)
d = e
while (d * e) % v != 1:
	d = d + 1

print('Private key: {' + str(d) + ',' + str(n) + '}')

msg = input('Please enter the message to be encrypted:\n')

#Convert message to ASCII representation
msg_array = []
for i in range(len(msg)):
	msg_array.append(ord(msg[i]))

#Encrypt Message
print("Encrypted Message:")
cipher_message = [int((math.pow(i, e))) % n for i in msg_array]
for i in range(len(cipher_message)):
	print(chr(cipher_message[i]), end = ' ')
	
	
#Decrypt the Message
decrypt_array = []
for i in range(len(cipher_message)):
	decrypt_array.append(chr(cipher_message[i] ** d % n))
print()

print("Decrypted Message:")
for i in range(len(decrypt_array)):	
	print(decrypt_array[i], end = '')