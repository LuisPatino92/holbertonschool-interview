#!/usr/bin/python3
""" Algorythm excercise """


def canUnlockAll(boxes):
    """
    Checks whether all boxes can be unlocked
    """

    amount_boxes = len(boxes)
    hash_dict = {0: True}
    while (True):

        amount_keys = len(hash_dict)

        for i in range(len(boxes)):
            if boxes[i] and hash_dict.get(i, False):
                for j in boxes[i]:
                    if j < amount_boxes:
                        hash_dict[j] = True
                    boxes[i] = None

        if not (len(hash_dict) > amount_keys):
            break

    if amount_keys == len(boxes):
        return True

    return False