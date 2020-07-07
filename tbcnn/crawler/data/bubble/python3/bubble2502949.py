q = int(input())

sort1 = list(map(int, input().split()))

def bubblesort(ary):
    cnt = 0
    for i in range(q):
        for j in range(q-1, i, -1):
            if ary[j] < ary[j-1]:
                ary[j-1], ary[j] = ary[j], ary[j-1]
                cnt += 1
    return (ary, cnt)

ary, cnt = bubblesort(sort1)
print(" ".join(map(str, ary)))
print(cnt)
