#!/usr/bin/python3
"""Interview problem - lockboxes"""


def canUnlockAll(boxes):
    """
    - boxes is a list of lists
    - A key with the same number as a box opens that box
    - You can assume all keys will be positive integers
    - The first box boxes[0] is unlocked
    - Return True if all boxes can be opened, else return False
    """
    def integrate_box(box, hash):
        """ Auxiliar function """
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
            try:
                hash_dict = integrate_box(boxes[j], hash_dict)
            except:
                pass
    return True
