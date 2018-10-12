print('Enter the number n')
a = int(input())

def recurse(a):
	if a is 0:
		return 0
	elif a is 1:
		return 1
	else:
		return a+recurse(a-1)

b=recurse(a)
print(b)