#ALDS1_2_B:   Selection Sort

def selectionSort(A, n):
    res = 0
    for i in range(n):
        minj = i
        for j in range(i, n):
            if A[j] < A[minj]:
                minj = j
                
        if A[i] != A[minj]:
            A[i], A[minj] = A[minj], A[i]        
            res += 1
        
    return A, res

n = int(input())
l = list(map(int, input().split()))
res_l, res = selectionSort(l, n)
print(*res_l)
print(res)
