def pascal_triangle(n):
    """
    Generate Pascal's Triangle up to the nth row.
    """
    if n <= 0:
        return []

    triangle = [[1]]  # First row
    
    for i in range(1, n):
        prev_row = triangle[-1]  # Last row of current triangle
        new_row = [1]  # Every row starts with 1

        # Generate middle values by summing adjacent values from previous row
        for j in range(1, len(prev_row)):
            new_row.append(prev_row[j - 1] + prev_row[j])

        new_row.append(1)  # Every row ends with 1
        triangle.append(new_row)  # Append new row to triangle

    return triangle
