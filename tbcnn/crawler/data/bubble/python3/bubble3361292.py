def bobbleSort(L, n):
  cnt = 0
  flag = True
  while flag:
    flag = False
    for i in range(n-1, 0, -1):
      if L[i] < L[i-1]:
        L[i], L[i-1] = L[i-1], L[i]
        flag = True
        cnt += 1
  return L, cnt

N = int(input())
A = list(map(int, input().split()))
A, t = bobbleSort(A, N)
print(' '.join(map(str, A)), t, sep='\n')
