# Solution by Ben Anspach, Nick Epps, and Aiden Morris
# Original problem: https://open.kattis.com/problems/artinstallation
[r,g,b] = [int(x) for x in input().split()]
[ar, ag, ab] = [int(x) for x in input().split()]
[comboRG, comboGB] =  [int(x) for x in input().split()]

neededR = max(0, r - ar)
neededG = max(0, g - ag)
neededB = max(0, b - ab)

comboRG -= neededR
comboGB -= neededB

if comboRG < 0 or comboGB < 0:
    print(-1)
elif comboRG + comboGB - neededG < 0:
    print(-1)
else:
    print(neededB + neededG + neededR)