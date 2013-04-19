from collections import deque

g = deque([1, 2, 3, 4])

for i in range(len(g)):
    #print g #or do anything with permutation
    g.rotate(1) #for right rotation
    #or g.rotate(-1) for left rotation

