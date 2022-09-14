#!/usr/bin/python3
"""
Metrics printer
"""

import signal
import sys

def print_metrics():
    print("File size: {}".format(total_size))
    for metric in sorted(counter.keys()):
        print("{}: {}".format(metric, counter[metric]))


def keyboardInterruptHandler(signal, frame):
    print_metrics()
    exit(0)


signal.signal(signal.SIGINT, keyboardInterruptHandler)

counter = {}

count = 0
total_size = 0

for lines in sys.stdin:
    try:
        count += 1
        parsed_line = int(lines.split(" ")[7])
        total_size += int(lines.split(" ")[8])
        
        if parsed_line in counter.keys():
            counter[parsed_line] += 1
        else:
            counter[parsed_line] = 1

        if (count == 9):
            print_metrics()
            count = 0

    except KeyboardInterrupt():
        keyboardInterruptHandler()
