#RSA Algorithm 
#By Sumukha Pk

import math
import random

def check_prime(a):
    flag = 1
    if(a==1):
        flag = 0
    for i in range(2,math.ceil(math.sqrt(a))):
        if(a%i == 0):
            flag = 0
            break
    return flag

def phi(p,q):
    return (p-1)*(q-1)

def gcd(a,b):
    if(b==0):   
        return a
    else:
        return gcd(b,a%b)

def finding_exp(p,q):
    phi_v = phi(p,q)
    e = random.randrange(1, phi_v)

    g = gcd(e, phi_v)
    while g != 1:
        e = random.randrange(1, phi_v)
        g = gcd(e, phi_v)
    
    return e

    
def find_pk(e,phi):
    e = e%phi
    for x in range(phi):
        if((e*x)%phi==1):
            return x


print('Enter two prime numbers(above 15):\n')
a = int(input('a: '))
b = int(input('b: '))

while(not(check_prime(a))&(a>16)):
    a = int(input('a is either not prime or is less than 15. Enter a prime number a: '))

while(not(check_prime(b))&(b>16)):
    b = int(input('b is either not prime or is less than 15. Enter a prime number b: '))

n = a * b    

#Public key -> (exp,n)
exp = finding_exp(a,b) 


#Private key -> (private_key,n)
private_key = find_pk(exp,phi(a,b))

message = input('Enter the message/number to be encrypted: ')

print('The encrypted data is ....')
encrypted_data = [(ord(char) ** exp) % (a*b) for char in message]

print (''.join(map(lambda x: str(x), encrypted_data)))


print('The decrypted data is.....')
decrypted_data = [chr((char ** private_key) % (a*b)) for char in encrypted_data]

print(''.join(decrypted_data))