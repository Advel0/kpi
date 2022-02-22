import matplotlib.pyplot as plt


def get_sum(list1, list2):
    list = []

    for i in range(len(list1)):
        list.append(list1[i]+list2[i])
    return list


class ChartBuilder:
    def __init__(self, _sorted, _reversed, _random, _omega, _big_o):
        self.sorted = _sorted
        self.reversed = _reversed
        self.random = _random
        self.omega = _omega
        self.big_o = _big_o

    def build(self):
        figure = plt.figure()
        
        # Drawing Frst Chart
        ax1 = figure.add_subplot(1,2,1)
        ax1 = self.draw_first_char(ax1, plt)

        # Drawing Second Chart
        # ax2 = figure.add_subplot(1,2,2)
        # ax2 = self.draw_second_chart(ax2, plt)
        
        plt.show()

    def draw_first_char(self, ax, plt):

        ax.set_title('Swaps Based Chart')

        ax.plot(self.sorted.get_swaps()[0], self.sorted.get_swaps()[1], 'g', label = 'sorted')
        ax.plot(self.reversed.get_swaps()[0], self.reversed.get_swaps()[1], 'r', label = 'reversed' )
        
        ax.plot(self.random.get_swaps()[0], self.random.get_swaps()[1], 'b', label = 'random' )
        ax.plot(self.big_o.get_swaps()[0], self.big_o.get_swaps()[1], 'm--', dashes=(5,10), label = 'worst(Big O)')
        ax.plot(self.omega.get_swaps()[0], self.omega.get_swaps()[1], 'y--', color='#f6ff00', dashes=(5,10), label = 'best(Big Omega)')

        plt.legend()
        return ax

    def draw_second_chart(self,ax, plt):

        ax.set_title('Swaps + Comparisons Based Chart')
        
        self.sorted.get_swaps()[0]

        ax.plot(self.sorted.get_swaps()[0],get_sum(self.sorted.get_comps()[1], self.sorted.get_swaps()[1]) , 'g', label = 'sorted')
        ax.plot(self.reversed.get_swaps()[0],get_sum(self.reversed.get_comps()[1], self.reversed.get_swaps()[1]) , 'r', label = 'reversed' )
        ax.plot(self.random.get_swaps()[0], get_sum(self.random.get_comps()[1], self.random.get_swaps()[1]), 'b', label = 'random' )
        ax.plot(self.big_o.get_swaps()[0], get_sum(self.big_o.get_comps()[1], self.big_o.get_swaps()[1]), 'm--', dashes=(5,10), label = 'worst(Big O)')
        ax.plot(self.omega.get_swaps()[0], get_sum(self.omega.get_comps()[1], self.omega.get_swaps()[1]), 'y--', color='#f6ff00', dashes=(5,10), label = 'best(Big Omega)')
    
        plt.legend()
        return ax