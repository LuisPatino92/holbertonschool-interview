#!/usr/bin/python3
""" Algorythm excercise """


def canUnlockAll(boxes):
    """
    Checks whether all boxes can be unlocked
    """

    hash_dict = {0: True}
    n_boxes = len(boxes)
    while (True):

        amount_keys = len(keys)

        for i in range(len(boxes)):
            if boxes[i] and hash_dict.get(i, False):
                for j in boxes[i]:
                    if j < n_boxes:
                        hash_dict[j] = True
                    boxes[i] = None

        if not (len(hash_dict) > amount_keys):
            break

    if amount_keys == len(boxes):
        return True

    return False
