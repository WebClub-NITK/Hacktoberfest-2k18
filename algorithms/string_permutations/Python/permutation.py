# program to find all possible permutations of given string
# Run in python 3

from itertools import permutations 
string = input("Enter the string Ex. ABC:-")
permList = permutations(string) 
for perm in list(permList): 
    print (''.join(perm)) 
        
