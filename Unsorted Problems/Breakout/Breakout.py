# Written by Aiden K Morris
# Original solution: https://open.kattis.com/problems/breakout2
[n, x, m] = [int(i) for i in input().split()]
crates = [int(input()) for _ in range(m)]

cratesLeft = 0
cratesRight = 0

for c in crates:
    if c >= 1 and c < x:
        cratesRight += 1
    else:
        cratesLeft += 1

print(min(cratesLeft, cratesRight))