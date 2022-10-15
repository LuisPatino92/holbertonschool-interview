#!/usr/bin/python3
""" Module Docstring """
import sys


def print_st(dic, size):
    """ Log printer """
    print("File size: {:d}".format(size))
    for i in sorted(dic.keys()):
        if dic[i] != 0:
            print("{}: {:d}".format(i, dic[i]))


sts = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
    }

count = 0
size = 0

try:
    for l in sys.stdin:
        if count != 0 and count % 10 == 0:
            print_st(sts, size)

        stlist = l.split()
        count += 1

        try:
            size += int(stlist[-1])
        except:
            pass

        try:
            if stlist[-2] in sts:
                sts[stlist[-2]] += 1
        except:
            pass
    print_st(sts, size)


except KeyboardInterrupt:
    print_st(sts, size)
    raise
