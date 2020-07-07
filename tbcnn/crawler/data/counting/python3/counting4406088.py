def counting_sort(A, B, k):
    C = [0]*k 
    for a in A:
        C[a] += 1
    for i in range(1, k):
        C[i] += C[i - 1] 
    for a in A:
        B[C[a] - 1] = a
        C[a] -= 1

n = int(input())
arr = list(map(int, input().split()))
B = [0]*n
counting_sort(arr, B, 10001)
print(*B)
