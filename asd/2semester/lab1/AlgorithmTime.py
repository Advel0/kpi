class AlgorithmTime:
    def __init__(self, _swaps={} , _comps={}):
        self.swaps = _swaps
        self.comparisons = _comps

    def get_swaps(self):
        return [ [key for key in self.swaps.keys() ], [value for value in self.swaps.values()]]
    
    def get_comps(self):
        return [ [key for key in self.comparisons.keys() ], [value for value in self.comparisons.values()] ]
    
    def gener_time_from_function(self,function, list):
        dict = {

        }

        for n in list:
            dict[n] = function(n)
            
        self.swaps = dict  