#!/usr/bin/python3
""" Solution of the exercise """


def minOperations(n):
    """
    Docstring
    """

    if type(n) == int:
        ooerations = 0
        i = 2
        while (i <= n):
            if n % i != 0:
                n = int(n / i)
                ooerations += i
                i = 1
            i += 1
        return op
    else:
        return 0
