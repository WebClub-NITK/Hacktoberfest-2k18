import sys
import numpy as np

def bubble_sort(arr):
    tam = len(arr)
    for y in range(tam):
        for x in range(0, tam-1):
            if (arr[x] > arr[x+1]):
                aux = arr[x]
                arr[x] = arr[x+1]
                arr[x+1] = aux
    print 'After Bubble Sort: ', arr


if __name__ == '__main__':
    arr = []
    for x in range(1, len(sys.argv)):
        arr.append(sys.argv[x])

    x = ','.join(arr)
    x = np.fromstring(x, dtype=np.integer, sep=',')
    print 'Initial array:', x
    bubble_sort(x)
