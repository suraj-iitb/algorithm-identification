def bubbleSort(A, N):
      ctn = 0
      for i in range(0,N):
            for j in range(0,N-i-1):
                  if int(A[j]) > int(A[j+1]):
                        t = A[j]
                        A[j] = A[j+1]
                        A[j+1] = t
                        ctn = ctn + 1
      for i in range(0,N):
            if i < N-1:
                  print(A[i],end=' ')
            else:
                  print(A[i])
      print(ctn)

if __name__ == "__main__":
      N = int(input())
      A = input()
      A = A.split()
      bubbleSort(A, N)
