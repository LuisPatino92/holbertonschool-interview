#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = []

keys = []
for n in range(1, 1000):
    keys = []
    for m in range(1, 1000):
        keys.append(m)
    boxes.append(keys)

print(canUnlockAll(boxes))