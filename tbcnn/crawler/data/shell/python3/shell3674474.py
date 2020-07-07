# -*- coding: utf-8 -*-
# ALDS1_2_D

def insertionSort(A, g=1):
    cnt = 0
    for i in range(g, len(A)):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v
    return A,cnt

def shellSort(A):
    n = len(A)
    cnt = 0
    m = 0
    G = []
    
    # 3m + 1 間隔でGを設定
    while 1:
        m = 3*m + 1
        if m > n:
            break
        G.insert(0, m)
        
    for i in G:
        A, c = insertionSort(A, i)
        cnt += c 
    return A,G,cnt

n = int(input())
A = []
for _ in range(n):
    A.append(int(input()))
sortedA, G, cnt = shellSort(A)

print(len(G))
print(" ".join(list(map(str, G))))
print(cnt)
for i in A:
    print(i)
    
