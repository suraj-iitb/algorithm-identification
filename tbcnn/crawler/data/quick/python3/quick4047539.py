# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_C&lang=ja

def partition(A, p, r):
    x = A[r][0]
    i = p - 1
    for j in range(p, r):
        if A[j][0] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[r] = A[r], A[i+1]
    return i + 1

def quicksort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quicksort(A, p, q - 1)
        quicksort(A, q + 1, r)

n = int(input())
A = []
valset = set({})
for i in range(n):
    c, d = input().split()
    A.append((int(d), i, c))
    valset.add(int(d))

quicksort(A, 0, n - 1)

# flag
is_stable = True
for val in valset:
    tp = [A[j][1] for j in range(n) if A[j][0] == val]
    flag = False
    for j in range(len(tp) - 1):
        if tp[j] > tp[j + 1]:
            flag = True
            break
    # print(val, tp, flag)
    if flag:
        is_stable = False
        break
    
if is_stable:
    print("Stable")
else:
    print("Not stable")

for tp in A:
    print("{} {}".format(tp[2], tp[0]))
