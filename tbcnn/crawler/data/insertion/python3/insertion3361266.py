def insertionSort(L, n):
  for i in range(n):
    v = L[i]
    j = i - 1
    while j >= 0 and L[j] > v:
      L[j+1] = L[j]
      j -= 1
    L[j+1] = v
    print(' '.join(map(str, L)))

N = int(input())
A = list(map(int, input().split()))
insertionSort(A, N)
