def selective_sort(A):
    global N
    i = 0 
    swap = 0
    while i < N-1:
        mini = i 
        for j in range(i+1, N):
            if A[j] < A[mini]:
                mini = j
        if mini != i:
            A[i],A[mini] = A[mini],A[i]
            swap += 1
        i += 1
    return swap 

N = int(input())
A = list(map(int, input().split()))
swap = selective_sort(A)
print(' '.join(list(map(str, A))))
print(swap)

            
