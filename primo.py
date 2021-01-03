#!/bin/python3

import sys

n_avaliado = int(sys.argv[1])
n_limite = int(sys.argv[2])

count = 0

while (n_avaliado < n_limite):
    primo = True
    for divisor in range(2, int(n_avaliado/2)):
        if (n_avaliado % divisor == 0):
            primo = False
            break

    if primo:
        count += 1
    ##    print(n_avaliado, end="\t")
    n_avaliado = n_avaliado + 1


print(count)
