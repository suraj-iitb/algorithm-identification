import copy

def partition(A,p,r):
    x = A[r][1]
    i = p-1
    # iは必ず1ずつ増える、jでx以下の要素を検出し、iの位置に持って行く
    for j in range(p,r):
        if A[j][1] <= x:
            i += 1
            A[i],A[j] = A[j],A[i]
    A[i+1],A[r] = A[r],A[i+1]
    return i+1

def quickSort(A,p,r):
    if p < r:
        q = partition(A,p,r)
        quickSort(A,p,q-1)
        quickSort(A,q+1,r)

N = int(input())
card = [input().split() for i in range(N)]
for i in range(N):
    card[i][1] = int(card[i][1])

card2 = copy.deepcopy(card)
card2.sort(key=lambda x: x[1])

quickSort(card,0,N-1)
#print(card)
#print(card2)

ans = 'Stable'
for i in range(N):
    if card[i][0] != card2[i][0]:
        ans = 'Not stable'
        break
print(ans)
for i in range(N):
    print(' '.join(map(str,card[i])))

