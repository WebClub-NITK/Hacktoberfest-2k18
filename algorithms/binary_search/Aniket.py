def binarysearch(arr,x):
 l=0
 r=len(arr)-1
 while(l<=r):
  mid=(l+r)//2
  if(arr[mid]==x):
   return mid
  elif(arr[mid]>x):
   r=mid-1
  else:
   l=mid+1
 return -1

print(binarysearch(list(map(int,input().split())),int(input('Number to search: '))))

