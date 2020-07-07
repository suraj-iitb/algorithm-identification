def insertionSort(A,N):
  for i in range(N):
      j = i
      while (j > 0) and (A[j-1] > A[j]) :
          tmp = A[j-1]
          A[j-1] = A[j]
          A[j] = tmp
          j -= 1
      print(' '.join(map(str, A)))
 
N = input()
N = int(N)
A = input()
A = list(map(int, A.split()))
insertionSort(A,N)
