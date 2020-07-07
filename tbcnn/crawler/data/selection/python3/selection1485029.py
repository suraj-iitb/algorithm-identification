#coding:utf-8
#1_2_B
def selection_sort(ary, n):
    count = 0
    for i in range(n):
        minj = i
        for j in range(i, n):
            if ary[minj] > ary[j]:
                minj = j
        if ary[minj] != ary[i]:
            ary[minj], ary[i] = ary[i], ary[minj]
            count += 1
    print(*ary)
    print(count)

n = int(input())
selection_sort(list(map(int, input().split())), n)
