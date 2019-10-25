from tools.csv_tools import write_csv, rows_to_columns
from tools.profiler import profile_instance
from tools.record_tools import generate_records
from numpy.random import RandomState

from instancegenerators.uniform_elements import generate_uniform_elements

SEED_MULTIPLIER = 97884319
SEED_DEVIATION = 17051314
SEED_SPREAD = 92927118

deviation_random = RandomState(SEED_DEVIATION)
spread_random = RandomState(SEED_SPREAD)
multiplier_random = RandomState(SEED_MULTIPLIER)


def gen_instance(n, algorithm):
    return (generate_uniform_elements(n=n, multiplier_deviation=deviation_random.uniform(1.0, 20),
                                      gain_spread_percentage=spread_random.uniform(1, 5),
                                      next_multiplier=multiplier_random.uniform), algorithm is "Floyd", 30)


def gen_algorithm(n):
    return ['Floyd', 'BellmanFord']


write_csv('results/arbitraje_over_n_cases.csv',
          generate_records(
              dimensions=[
                  ('n', lambda: range(2, 50)),
                  ('algorithm', gen_algorithm)
              ],
              generators=[
                  ('algorithm_time', gen_instance)
              ]
          )
          )
