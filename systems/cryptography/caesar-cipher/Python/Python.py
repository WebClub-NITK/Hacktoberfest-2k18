string = input('Enter the string to be encrypted here: (alphabets only) ')

key = int(input('Enter the key to be used to encode data(number): '))

key = key%26

string = list(string)

l = len(string)

for i in range(l):
    if((string[i]>='a')&(string[i]<='z')):
        x = ord(string[i])-ord('a')
        x+=key
        x=x%26
        string[i]=chr(x+ord('a'))
    if((string[i]>='A')&(string[i]<='Z')):
        x = ord(string[i])-ord('A')
        x+=key
        x=x%26
        string[i]=chr(x+ord('A'))


print('Caesar cipher: ')
print("".join(string))


