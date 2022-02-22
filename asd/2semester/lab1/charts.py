# from re import S
import random as rnd
from secrets import randbelow
from combSort import comb_sort
from math import log2

import matplotlib.pyplot as plt
from AlgorithmTime import AlgorithmTime
from chartBuilder import ChartBuilder

comparisons = {
        10: 45,
        100: 4950,
        1000: 499500,
        5000: 12497500,
        10000: 49995000,
        20000: 199990000,
        50000: 1249975000,
}

def main():
    
    def big_o_func(n):
        return n*log2(n)

    def omega_func(n):
        return 0
    

    range_ = [ 10,100,1000,5000, 20000, 50000]

    
# sorted = AlgorithmTime(
#     {
#         10: 0,
#         100: 0,
#         1000: 0,
#         5000: 0,
#         10000: 0,
#         20000: 0,
#         50000: 0,
#     },
#     comparisons

# )
    reversed = AlgorithmTime()
    random = AlgorithmTime()
    sorted = AlgorithmTime()


       
    

    dict_r_s ={}
    dict_r_c ={}
    for n in range_:
        arr = [i for i in range(n)]
        arr.reverse()
        tuple1 = comb_sort(arr)
        # print(tuple1)
        dict_r_c[n] = tuple1[0]
        dict_r_s[n] = tuple1[1]
    reversed.comparisons = dict_r_c
    reversed.swaps = dict_r_s


    dict_rand_s ={}
    dict_rand_c ={}
    for n in range_:
        arr = [i for i in range(n)]
        rnd.shuffle(arr)
        tuple2 = comb_sort(arr)
        dict_rand_c[n] = tuple2[0]
        dict_rand_s[n] = tuple2[1]

    random.comparisons = dict_rand_c
    random.swaps = dict_rand_s

    dict_sort_s ={}
    dict_sort_c ={}
    for n in range_:
        arr = [i for i in range(n)]
        tuple3 = comb_sort(arr)
        dict_sort_c[n] = tuple3[0]
        dict_sort_s[n] = tuple3[1]
        print(tuple3[1])
        print(dict_sort_s[n])
    sorted.comparisons = dict_sort_c
    sorted.swaps = dict_sort_s


 

    
    print(sorted.get_swaps())
    print(reversed.get_swaps())
    print(random.get_swaps())

    omega = AlgorithmTime(_comps = comparisons)
    omega.gener_time_from_function(omega_func, list(reversed.comparisons.keys()))

    big_o = AlgorithmTime(_comps = comparisons)
    big_o.gener_time_from_function(big_o_func,list(reversed.comparisons.keys()))

    cb = ChartBuilder(sorted, reversed, random,omega, big_o)

    cb.build()


# comparisons = {
#         10: 45,
#         100: 4950,
#         1000: 499500,
#         5000: 12497500,
#         10000: 49995000,
#         20000: 199990000,
#         50000: 1249975000,
# }

# sorted = AlgorithmTime(
#     {
#         10: 0,
#         100: 0,
#         1000: 0,
#         5000: 0,
#         10000: 0,
#         20000: 0,
#         50000: 0,
#     },
#     comparisons

# )
# reversed =  AlgorithmTime(
#     {
#         10: 45,
#         100: 4950,
#         1000: 499500,
#         5000: 12497500,
#         10000: 49995000,
#         20000: 199990000,
#         50000: 1249975000,
#     },
#     comparisons
# )
# random =  AlgorithmTime(
#     {
#         10: 26,
#         100: 2642,
#         1000: 251401,
#         5000: 6195007,
#         10000: 25055888,
#         20000: 99971380,
#         50000: 626023361,
#     },
#     comparisons
# )



main()

