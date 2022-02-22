import random


def bubble_sort(arr):
    count_swaps = 0
    count_comps = 0
    length = len(arr)
    for i in range(0, length):
        for j in range(1,length-i):
            count_comps+=1
            if arr[j] < arr[j-1]:
                count_swaps+=1
                temp = arr[j]
                arr[j] = arr[j-1]
                arr[j-1] = temp
    return (count_comps, count_swaps, )
# size = int(input('Enter array size: '))

# arr = [i for i in range(size)]
# random.shuffle(arr)
# print('Initial array: \n',arr)
# bubble_sort(arr)
# print('Sorted array: \n', arr)
