#!/usr/bin/python3
""" Algorithmic excercise """


def canUnlockAll(boxes):
    amount_of_boxes = len(boxes)
    hash_dict = {}
    [*map(lambda x: hash_dict.update({x: x}), boxes[0])]

    for i in range(1, amount_of_boxes):
        if i not in hash_dict.keys():
            return False
        [*map(lambda x: hash_dict.update({x: x}), boxes[i])]
    return True
