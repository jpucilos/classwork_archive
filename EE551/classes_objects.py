class Employee:
	salary=0
	name=0
	age=0

	def __init__(self,salary,name,age):
		self.salary = salary
		self.name = name
		self.age = age
	def raiseSalary(self):
		self.salary = self.salary*0.1 + self.salary

	def printSalary(self):
		print self.salary

E1 = Employee(1000, 'Bob', 45)
E2 = Employee(2000, 'Mary', '49')
E3 = Employee(3000, 'Smith', '97')

print E1.age
print E1.name

#you can do this
E2.title = 'Boss'
#can't do this in other languages, it's dope

print E2.title

E2.raiseSalary()
print E2.salary

#Create a list of objects, you can do tings to it
L = [E1, E2, E3] 

for item in L:
	print item.name

for item in L:
	print item.raiseSalary()

for person in L:
	print person.name
	print person.age
	print person.salary
	print "------"
