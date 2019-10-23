from decimal import *

from statistics import mean, median

getcontext().prec = 3

from subprocess32 import Popen, PIPE, STDOUT
from functools import reduce
import resource

def run_algorithm(instance, algorithm, times):
    print("Running... " + str(['../bin/arbitraje']) + " with instance:")
    print(instance)

    process = Popen(['../bin/knapsack', '-a', algorithm, '-p', str(times)], stdout=PIPE, stdin=PIPE, stderr=STDOUT)
    process.stdin.write(instance.encode())
    process.stdin.close()

    for line in iter(process.stdout.readline, b''):
        yield Decimal(float(line))

def profile_instance(instance, algorithm, times):
    return mean(list(run_algorithm(instance, algorithm, times)))
