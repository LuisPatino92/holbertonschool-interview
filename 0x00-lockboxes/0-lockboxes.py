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

        for box in range(len(boxes)):
            if boxes[box] and hash_dict.get(box, False):
                for key in boxes[box]:
                    if key < amount_boxes:
                        hash_dict[key] = True
                    boxes[box] = None

        if not (len(hash_dict) > amount_keys):
            break

    if amount_keys != len(boxes):
        return False

    return True
