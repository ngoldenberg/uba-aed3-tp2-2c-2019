from .program_input import AlgorithmInput


def generate_uniform_elements(n, multiplier_deviation, gain_spread_percentage, next_multiplier):
    def m():
        return next_multiplier(0, (1 * multiplier_deviation))

    matrix = [[0 for x in range(n)] for y in range(n)]
    for i in range(n):
        for j in range(i, n):
            if j == i:
                matrix[i][j] = 1.00
                continue
            multiplier = float("{0:.2f}".format(m()))
            matrix[i][j] = multiplier
            matrix[j][i] = float("{0:.2f}".format(1 / multiplier / 100 * gain_spread_percentage))

    return str(AlgorithmInput(n, matrix))
