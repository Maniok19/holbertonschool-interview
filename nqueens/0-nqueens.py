#!/usr/bin/python3
import sys

def check_other_queen(pos, row, col):
    for r, c in pos:
        if c == col:
            return False
        if abs(r - row) == abs(c - col):
            return False
    return True

def compute_queens(n, pos):
    row = len(pos)
    if row == n:
        print(pos)
        return

    for j in range(n):
        if check_other_queen(pos, row, j):
            pos.append((row, j))
            compute_queens(n, pos)
            pos.pop()

def check_all_start(n, pos=[]):
    for k in range(n):
        i_pos = [(0, k)]
        compute_queens(n, i_pos)

def main():
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)
    result = check_all_start(n)
    return result


if __name__ == "__main__":
    main()