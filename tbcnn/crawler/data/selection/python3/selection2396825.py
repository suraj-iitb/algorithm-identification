N = int(input())
A = [int(i) for i in input().split()]

def SelectionSort(N, A):
    cnt = 0
    for i in range(N):
        min_i = i
        for j in range(i, N):
            if A[j] < A[min_i]:
                min_i = j
        if i != min_i:
            A[i], A[min_i] = A[min_i], A[i]
            cnt += 1
    return A, cnt
    
res = SelectionSort(N, A)
print(" ".join(map(str, res[0])))
print(res[1])
