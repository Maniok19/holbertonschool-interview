#!/usr/bin/python3
"""
0_main
"""


def rain(walls):
    total = 0

    for i in range(len(walls)):
        left = max(walls[:i], default=0)
        right = max(walls[i+1:], default=0)

        water = min(left, right) - walls[i]

        if water > 0:
            total += water

    return total
