#!/usr/bin/python3
"""
This is the island_perimeter module
"""


def island_perimeter(grid):
    """
    returns the perimeter of the island described in grid
    """

    n = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j]:
                n += perimeter(grid, i, j)

    return n


def perimeter(grid, i, j):
    """
    Calculates the perimeter
    """

    num = 0

    if i <= 0 or not grid[i - 1][j]:
        num += 1
    if j <= 0 or not grid[i][j - 1]:
        num += 1
    if j >= len(grid[i]) - 1 or not grid[i][j + 1]:
        num += 1
    if i >= len(grid) - 1 or not grid[i + 1][j]:
        num += 1

    return num
