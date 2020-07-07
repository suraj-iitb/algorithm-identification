import sys
from sys import stdin
input = stdin.readline

n = int(input())
NUM_LIST = list(map(int, input().split()))
result = [0]*n

count = [0]*10001 #(max(NUM_LIST)+1)

for num in NUM_LIST:
    count[num] += 1

for i in range(1, len(count)):
    count[i] += count[i-1]

for num in NUM_LIST:
    result[count[num]-1] = num
    count[num] -= 1

print(" ".join(list(map(str, result))))

