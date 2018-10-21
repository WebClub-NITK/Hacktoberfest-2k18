import math
from random import *

def check_prime(a):
    flag = 1
    if(a==1):
        flag = 0
    for i in range(2,math.ceil(math.sqrt(a))):
        if(a%i == 0):
            flag = 0
            break
    return flag
def expo(x,y,z):
    for i in range(y):
        x*=x
        x%=z
    return x

print('Enter two prime numbers:\n')
g = int(input('g: '))
n = int(input('n: '))

while(not(check_prime(g))):
    g = int(input('g is not prime. Enter a prime number g: '))

while(not(check_prime(n))):
    n = int(input('n is not prime. Enter a prime number n: '))

a = randint(1,10000)
b = randint(1,10000)

print('Random keys chosen by 1 and 2 are %d and %d respectively.' % (a,b))

A = expo(g,a,n)
B = expo(g,b,n)

print('The keys exchanged by 1 and 2 are %d and %d respectively.' % (A,B))

RES1 = expo(A,b,n)
RES2 = expo(B,a,n)

print('The final results are : %d and %d ' % (RES1,RES2))