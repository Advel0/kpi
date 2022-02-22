from AlgorithmTest import AlgorithmTest


def bubble_sort(array: list, number_of_swaps: int, checking_number: int) -> list[int]:
    n = len(array)
    for _ in range(0, n, 1):
        for j in range(0, n-1, 1):
            checking_number += 1
            if(array[j] > array[j+1]):
                number_of_swaps += 1
                temp = array[j]
                array[j] = array[j+1]
                array[j+1] = temp
    return [number_of_swaps, checking_number]


def main():
    AlgorithmTest.test("Bubble sort", bubble_sort)


main()
