#!usr/bin/env python3
def canUnlockAll(boxes):
    opened = {0}
    ukeys = list(boxes[0])
    while ukeys:
        key = ukeys.pop()
        if 0 <= key < len(boxes) and key not in opened:
            opened.add(key)
            ukeys.extend(boxes[key])
    return len(opened) == len(boxes)

if __name__ == "__main__":
    canUnlockAll