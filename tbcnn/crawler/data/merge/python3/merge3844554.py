n = int(input())
S = list(map(int, input().split()))

cnt = 0

def merge(left, mid, right):
    global cnt
    n1 = mid - left
    n2 = right - mid
    L = S[left:left+n1]
    R = S[mid:mid+n2]
    L.append(10e10)
    R.append(10e10)
    for j in range(n2):
        R[j] = S[mid+j]
    x = 0
    y = 0
    for k in range(left, right):
        cnt += 1
        if L[x] < R[y]:
            S[k] = L[x]
            x += 1
        else:
            S[k] = R[y]
            y += 1

def mergesort(left, right):
    if left+1 < right:
        mid = (left + right)//2
        mergesort(left, mid)
        mergesort(mid, right)
        merge(left, mid, right)

mergesort(0, n)

print(*S)
print(cnt)
