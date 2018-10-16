def rsum(n):
   if n <= 1:
       return n
   else:
       return n + rsum(n-1)
 
def main():
    num = int(input("Enter a number: "))
    if num < 0:
        print("Enter a positive number")
    else:
        print("The sum is",rsum(num))

if __name__=="__main__":
    main()
