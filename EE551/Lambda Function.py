def add(x,y,z):
	return x + y +z

print add(1,2,3)

#lambda ARGS: ACTION
label = lambda x, y, z: x+y+z

print label(1,2,3)

L = [lambda x: x**2, lambda x: x**3, lambda x: x**4]

for item in L:
	print item(2)

def titleMe():
	title = "The Great"
	action = (lambda x: title + ' ' + x)
	return action

act = titleMe()
msg = act('Robin Hood')
print msg
