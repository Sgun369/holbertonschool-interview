#!/usr/bin/python3
"""Lockboxes"""


def canUnlockAll(boxes):
    """Determines if all boxes can be opened """
    if not boxes:
        return True

    n = len(boxes)
    visited = [False] * n
    queue = [0]

    visited[0] = True
    opened_boxes = 1

    while queue:
        current_box = queue.pop(0)
        for key in boxes[current_box]:
            if key < n and not visited[key]:
                visited[key] = True
                queue.append(key)
                opened_boxes += 1
    return opened_boxes == n
