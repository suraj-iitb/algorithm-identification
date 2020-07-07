# -*- coding:utf-8 -*-

def Selection_Sort(A,n):
    count = 0
    for i in range(n):
        mini = i
        for j in range(i,n): #i以上の要素において最小のAをminiに格納
            if A[j] < A[mini]:
                mini = j
        if A[i] != A[mini]:
            A[i], A[mini] = A[mini], A[i]
            count += 1
    return A, count

n = int(input())
numbers = list(map(int, input().split(" ")))

ans_list, count = Selection_Sort(numbers, n)
ans_list = map(str, ans_list)

print(" ".join(ans_list))
print(count)
