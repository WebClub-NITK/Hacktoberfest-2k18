#The majority element is the element that occurs more than half of the size of the array.

#Algorithm below loops through each element and maintains a count of a[maj_index], If next element is same then increments the count, if next element is not same then decrements the count, and if the count reaches 0 then changes the maj_index to the current element and sets count to 1. First Phase algorithm gives us a candidate element. In second phase we need to check if the candidate is really a majority element.

Second phase is simple and can be easily done in O(n). We just need to check if count of the candidate element is greater than n/2.

Moore’s Majority Algorithm:

c = particular candidate
Step 0: Initialize count to be zero
Step 1: Go through the vote
i. Check if the count is zero
if so then assign the c to this vote’s candidate and then set count=1
if not then check if this vote’s candidate is equal to c
if yes then set count+=1
if no then set count-=1
Step 2: Continue until the end
Step 3: For that c,Check once again by going through the votes if it is really the majority.