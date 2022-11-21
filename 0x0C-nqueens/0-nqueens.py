#!/usr/bin/python3
""" Module docstring"""
import sys


class NQueen:
    """ Class docstring """

    def __init__(self, n):
        """ Constructor """
        self.n = n
        self.x = [0 for i in range(n + 1)]
        self.res = []

    def place(self, k, i):
        """ Method Docstring"""

        # j checks from 1 to k - 1 (Up to previous q)
        for j in range(1, k):
            # There is already a q in column
            # or a q in same diagonal
            if self.x[j] == i or \
               abs(self.x[j] - i) == abs(j - k):
                return 0
        return 1

    def nQueen(self, k):
        """ Auxiliar method """
        for i in range(1, self.n + 1):
            if self.place(k, i):
                self.x[k] = i
                if k == self.n:
                    solution = []
                    for i in range(1, self.n + 1):
                        solution.append([i - 1, self.x[i] - 1])
                    self.res.append(solution)
                else:
                    self.nQueen(k + 1)
        return self.res

if len(sys.argv) != 2:
    print("Usage: nqs N")
    sys.exit(1)

N = sys.argv[1]

try:
    N = int(N)
except ValueError:
    print("N must be a number")
    sys.exit(1)

if N < 4:
    print("N must be at least 4")
    sys.exit(1)

q = NQueen(N)
res = q.nQueen(1)

for i in res:
    print(i)
