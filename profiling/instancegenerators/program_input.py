from itertools import chain

class AlgorithmInput:
    def __init__(self, n, matrix):
        self.n = n
        self.matrix = matrix

    def get_header_lines(self):
        return [str(self.n)]

    def get_element_lines(self):
        lines = []
        for row in self.matrix:
            row_values = []
            for column in row:
                row_values.append(column)
            lines.append(" ".join(row_values) + "\n")
        return lines

    def __str__(self):
        return "\n".join(chain(self.get_header_lines(), self.get_element_lines()))
