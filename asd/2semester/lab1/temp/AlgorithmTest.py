import random
from GraphHandler import GraphHandler


class AlgorithmTest():

    @staticmethod
    def test(algorithm_name: str, sorting_function):
        labels_colors = {'ordered': 'green', 'reversed': 'red',
                         'random': 'blue'}
        testing_sizes = [10, 100, 1000, 5000]
        testing_arrays = [[], [], []]
        testing_Xs = [[], [], []]
        testing_Ys = [[], [], []]
        testing_array_index = 0
        for array in testing_arrays:
            print("Array index: " + str(testing_array_index))
            for size in testing_sizes:
                if(testing_array_index == 0):
                    array = [i for i in range(1, size + 1)]
                elif(testing_array_index == 1):
                    array = [i for i in range(size, 0, -1)]
                elif(testing_array_index == 2):
                    array = [i for i in range(1, size+1)]
                    random.shuffle(array)
                number_of_swaps = 0
                checking_number = 0
                results = sorting_function(
                    array, number_of_swaps, checking_number)
                number_of_swaps = results[0]
                checking_number = results[1]
                print("Number of swaps: " + str(number_of_swaps))
                print("Number of checks: " + str(checking_number))
                testing_Ys[testing_array_index].append(number_of_swaps)
                testing_Xs[testing_array_index].append(size)
            testing_array_index += 1
        GraphHandler.draw_graph_for_algorithm(
            algorithm_name, testing_Xs, testing_Ys, labels_colors)
