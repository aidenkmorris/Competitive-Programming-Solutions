# Solution by Ben Anspach, Nick Epps, and Aiden Morris
# Original problem: https://open.kattis.com/problems/triplejump
n = int(input())
jumps = [int(x) for x in input().split()]

dist = [jumps[0] // 3, jumps[-1] // 3]

med = jumps[1] - 2 * dist[0]

print(str(dist[0]) + " " + str(med) + " " + str(dist[1]))