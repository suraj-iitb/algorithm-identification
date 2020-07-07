def selectionSort(L, n):
  cnt = 0
  for i in range(n):
    minj = i
    for j in range(i, n):
      if L[j] < L[minj]:
        minj = j
    L[i], L[minj] = L[minj], L[i]
    if i != minj:
      cnt += 1
  return L, cnt

N = int(input())
A = list(map(int, input().split()))
A, t = selectionSort(A, N)
print(' '.join(map(str, A)), t, sep='\n')
