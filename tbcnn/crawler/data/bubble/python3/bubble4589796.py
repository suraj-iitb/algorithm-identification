#ALDS1_2_A:   Bubble Sort

def b_sort(A, n):
    flag = True
    res = 0
    while flag:
        flag = False
        for j in range(n-1, 0, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                flag = True
                res += 1
    return A, res

n = int(input())
l = list(map(int, input().split()))
res_l, res = b_sort(l,n)
print(*res_l)
print(res)
