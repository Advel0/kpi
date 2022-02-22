import matplotlib.pyplot as plt


class GraphHandler():

    @staticmethod
    def draw_graph_for_algorithm(algorithm_type: str, array_of_all_Xs: list[int], array_of_all_Ys: list[int], labels_colors: dict):
        i = 0
        for key in labels_colors:
            plt.plot(array_of_all_Xs[i], array_of_all_Ys[i],
                     color=labels_colors[key], label=key)
            i += 1
        plt.xlabel('Number of elements')
        plt.ylabel('Number of replacements')
        plt.title(algorithm_type)
        plt.legend()
        plt.show()
