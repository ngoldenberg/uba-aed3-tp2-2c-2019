from decimal import *
from statistics import mean, median
import subprocess, os
from subprocess32 import Popen, PIPE, STDOUT

getcontext().prec = 3


def run_algorithm(instance, is_floyd=False, times=1):
    print("Running... {0} (algorithm: {1}) with instance:".format(str(['../bin/arbitraje']),
                                                                  "Floyd" if is_floyd else "BellmanFord"))
    print(instance)

    my_env = os.environ.copy()
    my_env["FLOYD"] = "true" if is_floyd else "false"
    my_env["TIME"] = "true"

    is_cycle = None
    average_time = 0
    for t in range(0, times):

        try:
            process = Popen(['../bin/arbitraje'], env=my_env, stdout=PIPE, stdin=PIPE,
                            stderr=STDOUT)
            process.stdin.write(instance.encode())
            process.stdin.close()
        except subprocess.CalledProcessError as e:
            print(e.output)
            raise RuntimeError(e.output)

        lines = [line for line in iter(process.stdout.readline, b'')]
        if len(lines) is 0:
            raise RuntimeError(
                "Null output for {0} algorithm with instance: \n{1}".format("Floyd" if is_floyd else "BellmanFord",
                                                                            instance))

        has_cycle = " ".split(str(lines[0]))[0] is "SI"
        elapsed_time = float(lines[1])

        if is_cycle is None:
            is_cycle = has_cycle
        else:
            if is_cycle is not has_cycle:
                raise RuntimeError("Same instance returned different cycle results")
        average_time = (average_time + elapsed_time) / 2

        return average_time, is_cycle


def profile_instance(instance, is_floyd=False, times=1):
    return mean(list(run_algorithm(instance, is_floyd, times)))
