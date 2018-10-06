#!/usr/bin/python3

def binary_search(array, number):
    length = len(array)
    if length == 0:    
        return False

    low = 0
    high = length - 1
    while low <= high:
        mid = (low + high) // 2
        if number < array[mid]:
            high = mid - 1
        elif number > array[mid]:
            low = mid + 1
        else:
            return mid
    else:
        return False

def main():
    test_array = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    found_item = binary_search(test_array, 3)
    print(found_item)
 
main()
