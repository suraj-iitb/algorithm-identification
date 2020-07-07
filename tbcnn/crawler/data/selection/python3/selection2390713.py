def selectSort(A, N):
      cnt = 0
      for i in range(0,N):
            mina = A[i]
            k = 0
            for j in range(i+1,N):
                  if int(mina) > int(A[j]):
                        mina = A[j]
                        k = j
            if int(A[i]) > int(mina):
                  swap = A[i]
                  A[i] = mina
                  A[k] = swap
                  cnt = cnt + 1
      for t in range(0,N):
            if t < N-1:
                  print(A[t], end=" ")
            else:
                  print(A[t])
      print(cnt)
            

if __name__ == "__main__":
      N = int(input())
      A = (input()).split()
      selectSort(A,N)
