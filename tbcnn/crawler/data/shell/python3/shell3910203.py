import sys
from sys import stdin
input = stdin.readline

def insertionSort(NUM_LIST, g, cnt):
    for i in range(g, len(NUM_LIST)):
        v = NUM_LIST[i]
        j = i - g
        while j >= 0 and NUM_LIST[j] > v:
            NUM_LIST[j+g] = NUM_LIST[j]
            j -= g
            cnt += 1
        NUM_LIST[j+g] = v
    return NUM_LIST, cnt

def shellSort(NUM_LIST):
    cnt = 0
    G = [1]
    a=1
    i=1
    while (a+3**i) < len(NUM_LIST):
        a += 3**i
        i+=1
        G.append(a)
    m = len(G)
    G = G[::-1]
    for i in G:
        NUM_LIST, cnt = insertionSort(NUM_LIST, i, cnt)
    return m, cnt, NUM_LIST, G

NUM_LIST = []
n = int(input())
for _ in range(n):
    NUM_LIST.append(int(input()))

m, cnt, NUM_LIST, G = shellSort(NUM_LIST)

print(m)
print(" ".join(list(map(str, G))))
print(cnt)
for num in NUM_LIST:
    print(num)
