import sys
from sys import stdin

cnt = 0

def BubbleSort(L):
    global cnt
    for i in range(len(L)):
        for j in range(len(L)-1, i, -1):
            if L[j-1] > L[j]:
                L[j-1], L[j] = L[j], L[j-1]
                cnt += 1
    
n = int(input())
NUM_LIST = list(map(int, input().split()))

BubbleSort(NUM_LIST)
STR = list(map(str, NUM_LIST))
print(" ".join(STR))
print(cnt)
