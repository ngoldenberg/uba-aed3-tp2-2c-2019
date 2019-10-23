from itertools import chain

class Order:
    def __init__(self, weight, profit):
        self.weight = weight
        self.profit = profit

class ProgramInput:
    def __init__(self, order_set, w):
        self.order_set = order_set
        self.w = w

    def get_header_lines(self):
        return [str(len(self.order_set)) + " " + str(self.w)]

    def get_element_lines(self):
        return (str(elem.weight) + " " + str(elem.profit) for elem in self.order_set)

    def __str__(self):
        return "\n".join(chain(self.get_header_lines(), self.get_element_lines()))
