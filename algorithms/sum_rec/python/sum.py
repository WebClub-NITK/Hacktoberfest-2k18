# your code goes here
def sum_rec(n):
	if(n==0):
		return 0
	else:
		return n+sum_rec(n-1)
	
	
n=int(input("Enter the number\n"))
print("Sum is :-",sum_rec(n))
