from collections import deque


def bucket_sort_deque(a):
    # Dequeは高速な双方向リスト，Pythonでリストを使うときにはDeque
    m = 10**5
    b = [deque() for _ in range(m)]
    for i in a:
        b[i].append(i)
    i = 0
    for d in b:
        while len(d) != 0:
            a[i] = d.pop()
            i += 1
n = int(input())
l = list(map(int,input().split()))
bucket_sort_deque(l)
for i in l[:n-1]:
    print(i,end = ' ')
print(l[-1])
