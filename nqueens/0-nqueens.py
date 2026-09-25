#!/usr/bin/python3
import sys


def is_safe(board, row, col):
    """Check if a queen can be placed at board[row][col]"""
    # Check this column
    for i in range(row):
        if board[i] == col:
            return False

    # Check upper left diagonal
    for i in range(row):
        if board[i] == col - (row - i):
            return False

    # Check upper right diagonal
    for i in range(row):
        if board[i] == col + (row - i):
            return False

    return True


def solve_nqueens(n, row, board, solutions):
    """Recursively solve N queens using backtracking"""
    if row == n:
        # Found a solution, add it to solutions
        solution = [[i, board[i]] for i in range(n)]
        solutions.append(solution)
        return

    for col in range(n):
        if is_safe(board, row, col):
            board[row] = col
            solve_nqueens(n, row + 1, board, solutions)
            # Backtrack
            board[row] = -1


def main():
    # Check number of arguments
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    # Try to convert argument to integer
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    # Check if N is at least 4
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    # Solve N queens
    board = [-1] * n
    solutions = []
    solve_nqueens(n, 0, board, solutions)

    # Print all solutions
    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    main()
