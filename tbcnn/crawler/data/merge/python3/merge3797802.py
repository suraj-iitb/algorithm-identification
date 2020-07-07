def merge(S, left, mid, right):
    INF = 10**9
    global cnt
    L = S[left: mid] + [INF]
    R = S[mid: right] + [INF]
    i = 0
    j = 0
    
    for k in range(left, right):
        cnt += 1
        if L[i] <= R[j]:
            S[k] = L[i]
            i += 1
        else:
            S[k] = R[j]
            j += 1

def mergeSort(S, left, right):
    if left+1 < right:
        mid = (left + right) // 2
        mergeSort(S, left, mid)
        mergeSort(S, mid, right)
        merge(S, left, mid, right)
        
n = int(input())
S = list(map(int, input().split()))

cnt = 0
mergeSort(S, 0, n)

print(" ".join(map(str, S)))
print(cnt)
