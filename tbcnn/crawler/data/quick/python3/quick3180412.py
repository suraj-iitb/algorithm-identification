import sys

def Partition(A, p, r):
    x = A[r][1]
    i = p-1
    for j in range(p, r):
        if A[j][1] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[r] = A[r], A[i+1]
    return i+1, A


def Quicksort(A, p, r):
    if p < r:
        q, A = Partition(A, p, r)
        A = Quicksort(A, p, q-1)
        A = Quicksort(A, q+1, r)
    return A

n = int(sys.stdin.readline())
cards = []
for _ in range(n):
    s,t = sys.stdin.readline().split()
    cards.append([s, int(t)])

orig = cards[:]
Quicksort(cards, 0, n-1)
mm=[c[0] for c in cards]
nn=[c[1] for c in cards]
cc=[]
for k in nn:
    if k in cc: continue
    cc.append(k)
    if nn.count(k)<=1: continue
    a=[]
    b=[]
    for o in orig:
        if o[1]==k:  a.append(o[0])
    for p in cards:
        if p[1]==k:  b.append(p[0])
    if a!=b:
        print('Not stable')
        break
else:
    print('Stable')

for c in cards:
    print(c[0],c[1])
