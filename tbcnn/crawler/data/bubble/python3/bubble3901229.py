
def babble_sort(A, N):
    cnt = 0
    flag = 1
    while flag:
      flag = 0
      i = 0
      for j in reversed(range(i + 1, N)):
        if A[j] < A[j-1]:
          c = A[j]
          A[j] = A[j -1]
          A[j-1] = c
          cnt += 1
          flag = 1
      i += 1
    for b in range(N):
      print(A[b], end=" \n"[b + 1 == N])
    print(cnt)


N = int(input())
A = list(map(int, input().split()))

babble_sort(A, N)
