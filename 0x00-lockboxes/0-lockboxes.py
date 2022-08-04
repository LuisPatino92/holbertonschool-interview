#!/usr/bin/python3
""" Algorithmic excercise """


def canUnlockAll(boxes):
    """You have `n` number of locked boxes in front of you.
    Each box is numbered sequentially from `0` to `n - 1`
    and each box may contain keychain to the other boxes.
    This function determines if all the boxes can be opened.
    * The first box boxes[0] is unlocked.
    Args:
        boxes (list): list of list containing keychain
    Returns:
        Bool: True if all boxes can be unlocked. False if fail
    """
    amount_of_boxes = len(boxes)
    hash_dict = {}
    [*map(lambda x: hash_dict.update({x: x}), boxes[0])]

    for i in range(1, amount_of_boxes):
        if i not in hash_dict.keys():
            return False
        [*map(lambda x: hash_dict.update({x: x}), boxes[i])]
    return True
