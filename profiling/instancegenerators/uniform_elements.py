from numpy.random import RandomState
from .program_input import ProgramInput, Order


def generate_unifrom_elements(n, W, weight_deviation, weight_spread, next_weight, next_profit):

    w_dev = weight_deviation*W
    w_spread = weight_spread*W

    weights_range_start = W - w_dev
    weights_range_end = weights_range_start + w_spread

    weights_range = (weights_range_start, weights_range_end)

    def w():
        return max(next_weight(weights_range[0], weights_range[1]), 1)

    def p():
        return next_profit(1, n + 1)

    return str(ProgramInput(
        [Order(w(), p()) for item in range(0, n)],
        W
    ))

