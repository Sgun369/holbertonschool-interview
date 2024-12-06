#!/usr/bin/env python3
"""module nqueens"""

import sys

def is_safe(board, row, col):
    """check if a queen can be placed on board[row][col] without being attacked"""
    for i in range(row):
        if board[i] == col:
            return False
        if abs(board[i] - col) == abs(i - row):
            return False
    return True

def solve_nqueens(n, row, board, solutions):
    """Recursively solve the N queens problem"""
    if row == n:
        # convert board state to solution format
        solutions.append([[i, board[i]] for i in range(n)])
        return
    
    for col in range(n):
        if is_safe(board, row, col):
            board[row] = col
            solve_nqueens(n, row +1, board, solutions)
            # backtrack
            board[row] = -1
def nqueens():
    """Main function to parse arguments and solve the N queens problem"""
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
        
    board = [-1] * n # initialize board with -1
    solutions = []
    solve_nqueens(n, 0, board, solutions)
    
    for solution in solutions:
        print(solution)
        
if __name__ == "__main__":
    nqueens()
