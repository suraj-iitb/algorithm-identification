def SelectionSort(A, N):
    cnt = 0
    for i in range(0, N):
      minj = i
      for j in range(i, N):
        if A[j] < A[minj]:
          minj = j
      if i != minj:
        cnt += 1      
      c = A[i]
      A[i] = A[minj]
      A[minj] = c

    for b in range(N):
      print(A[b], end=" \n"[b + 1 == N])
    print(cnt)


N = int(input())
A = list(map(int, input().split()))

SelectionSort(A, N)
