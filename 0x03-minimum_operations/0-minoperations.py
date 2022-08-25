#!/usr/bin/python3
""" Solution of the exercise """


def minOperations(n):
    """
    Docstring
    """

    if isinstance(n, int):
        operations = 0
        i = 2
        while (i <= n):
            if n % i == 0:
                n = int(n / i)
                operations += i
                i = 1
            i += 1
        return operations
    else:
        return 0
