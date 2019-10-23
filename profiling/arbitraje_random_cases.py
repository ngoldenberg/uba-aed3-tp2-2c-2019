from tools.csv_tools import write_csv, rows_to_columns
from tools.profiler import profile_instance
from tools.record_tools import generate_records
from numpy.random import RandomState

from instancegenerators.uniform_elements import generate_unifrom_elements

SEED_WEIGHTS = 97884319
SEED_PROFITS = 91558205

SEED_W = 58174575

SEED_DEVIATION = 17051314
SEED_SPREAD = 92927118

W_random = RandomState(SEED_W)
deviation_random = RandomState(SEED_DEVIATION)
spread_random = RandomState(SEED_SPREAD)
weights_random = RandomState(SEED_WEIGHTS)
profits_random = RandomState(SEED_PROFITS)

def gen_instance(index):
    return (generate_unifrom_elements(n=1000, W=1000, weight_deviation=deviation_random.uniform(0.0,0.1), weight_spread=spread_random.uniform(0.0,1.0), next_weight=weights_random.randint, next_profit=profits_random.randint), "bf", 30)

write_csv('results/arbitraje_random_cases.csv',
    generate_records(
        dimensions=[
            ('n', lambda: range(0, 100))
        ],
        generators=[
            ('algorithm_time', gen_instance)
        ]
    )
)

