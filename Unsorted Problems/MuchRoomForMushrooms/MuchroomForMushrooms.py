# Written by Aiden Morris, Ben Anspach, and Nick Epps
# Original problem: https://open.kattis.com/problems/muchroomformushrooms
import math
[r, c] = [int(n) for n in input().split()]

if c == 1:
    print(1)
elif r == 1:
    print(math.ceil(c / 3))
elif r == 2:
    print(c // 2 + 1)
else:
    print(-1)