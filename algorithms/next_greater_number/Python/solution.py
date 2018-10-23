num = input('Enter the number: ')
l = len(num)
len = l-1
while len>0:
    if(num[len]>num[len-1]):
        break
    len-=1
if(len==0):
    print('Next greatest number is not possible!')
else:
    least = len 
    x = num[len-1]
    for i in range(len+1,l):
        if((num[i]>x)&(num[i]<num[least])):
            least = i
    num = list(num)
    num[len-1], num[least] = num[least], num[len-1]
    num = num[0:len] + sorted(num[len:])
    
    num = "".join(num)
    print('The next greatest number is: ')
    print(num)

    
#Test cases: 
# 1. 1234 --> 1243
# 2. 4321 --> Not possible
# 3. 91857631 --> 91861357
# 4. 7163598 --> 7163859