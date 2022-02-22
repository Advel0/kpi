import random


def comb_sort(arr):
    count_swaps = 0
    count_comps = 0

    swapped = False 
    length = len(arr)
    gap = int(length/1.247)
    
    while gap > 1 or swapped == True:
        swapped = False
        for i in range(length - gap):
            count_comps+=1
            if arr[i] > arr[i+gap]:
                count_swaps+=1
                arr[i], arr[i+gap] = arr[i+gap], arr[i]
                swapped = True
        if gap > 1 :
            gap = int(gap/1.247)

    return (count_comps, count_swaps, )
# def comb_sort(arr):

#     swapped = False 
#     length = len(arr)
#     gap = int(length/1.247)
    
#     while gap > 1 or swapped == True:
#         swapped = False
#         for i in range(length - gap):
#             if arr[i] > arr[i+gap]:
#                 arr[i], arr[i+gap] = arr[i+gap], arr[i]
#                 swapped = True
#         if gap > 1 :
#             gap = int(gap/1.247)

    # print('swaps: ',)
    # print('=======')
    
range_ = [ 10,100,1000,5000,10000,20000, 50000,]

#SORTED
print('=============')
print("-SORTED")
for n in range_:
    arr = [i for i in range(n)]
    tuple = comb_sort(arr)
    print(n,':')
    print(tuple[0], tuple[1])

print('=============')
print("-REVERSED")
#REVERSED
for n in range_:
    arr = [i for i in range(n)]
    arr.reverse()
    tuple = comb_sort(arr)
    print(n,':')
    print(tuple[0], tuple[1])

print('=============')
print("-RANDOM")
#RANDOM
print('RANDOM VALUES')
for n in range_:
    arr = [i for i in range(n)]
    random.shuffle(arr)
    tuple = comb_sort(arr)
    print(n,':')
    print(tuple[0], tuple[1])

# list = [i for i in range(10)]
# random.shuffle(list)

# print(list)
# comb_sort(list)
# print(list)