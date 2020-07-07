#マージソート
from collections import deque
n = int(input())
S = list(map(int, input().split()))
INFTY = 1e9 + 1

def merge(S, left, mid, right):
    global cnt
    L = deque(S[left:mid])
    R = deque(S[mid:right])
    L.append(INFTY)
    R.append(INFTY)
    for k in range(left, right):
        S[k] = (L if L[0] < R[0] else R).popleft()
    cnt += right - left
    
def merge_sort(S, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        merge_sort(S, left, mid)
        merge_sort(S, mid, right)
        merge(S, left, mid, right)
        
cnt = 0
merge_sort(S, 0, n)
print(*S)
print(cnt)
