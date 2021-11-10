# Based on work: https://int-i.github.io/python/2021-11-07/matplotlib-google-benchmark-visualization/

from argparse import ArgumentParser
from itertools import groupby
import json
import math
import operator
import matplotlib.pyplot as plt

plt.rcParams['figure.figsize'] = [21, 12]


def extract_label_from_benchmark(benchmark):
    benchmark_name = benchmark['name']
    return benchmark_name.split('/')[0][3:]  # erase `BM_`


def extract_size_from_benchmark(benchmark):
    benchmark_name = benchmark['name']
    return benchmark_name.split('/')[1]  # not int, for exp scale x axis


if __name__ == "__main__":
    parser = ArgumentParser()
    parser.add_argument('path', help='benchmark result json file')
    args = parser.parse_args()

    with open(args.path) as file:
        benchmark_result = json.load(file)
        benchmarks = benchmark_result['benchmarks']
        elapsed_times = groupby(benchmarks, extract_label_from_benchmark)
        for key, group in elapsed_times:
            benchmark = list(group)
            x = list(map(extract_size_from_benchmark, benchmark))
            y = list(map(operator.itemgetter('bytes_per_second'), benchmark))
            #log_y = list(map(math.log, y))
            plt.plot(x, y, label=key, marker=None)
        plt.grid(color='green', linestyle='--', linewidth=0.2)
        plt.xlabel('Array size')
        plt.ylabel('Gigabyte per second (GB/s)')
        plt.title('CRC32 Algorithm Benchmark')
        plt.legend()
        plt.savefig('benchmark.png', bbox_inches='tight', dpi=300)
        # plt.savefig('benchmark.svg')
        plt.show()
