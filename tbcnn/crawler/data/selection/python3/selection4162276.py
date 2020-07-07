def selection_sort():
    N = int(input())
    A = [int(_) for _ in input().split()]

    ans = 0

    for i in range(N):
        minj = i 
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        A[i], A[minj] = A[minj], A[i]
        if i != minj:
            ans += 1
    
    print(' '.join(map(str, A)))
    print(ans)
        

selection_sort()

