#!/usr/bin/python3
""" Algorithmic excercise """


def canUnlockAll(boxes):
    """
    Interview like excercise
    """
    def integrate_box(box, hash):
        [*map(lambda x: hash.update({x: x}), box)]
        return hash

    amount_of_boxes = len(boxes)
    hash_dict = {}
    hash_dict = integrate_box(boxes[0], hash_dict)

    for i in range(1, amount_of_boxes):

        if i not in hash_dict.keys():
            return False
        hash_dict = integrate_box(boxes[i], hash_dict)
        for j in hash_dict.copy().keys():
            hash_dict = integrate_box(boxes[j], hash_dict)
    return True


boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))