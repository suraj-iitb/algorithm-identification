def s_sort(A,N):
   global count

   for i in range(N):
       min_j = i
       for j in range(i,N):
           if A[j] < A[min_j]:
               min_j = j

       if i != min_j:
           temp = A[i]
           A[i] = A[min_j]
           A[min_j] = temp
           count += 1

   return A
  
if __name__=='__main__':
    n = int(input())
    R = list(map(int,input().split()))
    count = 0
    R = s_sort(R,n)
    print(" ".join(map(str,R)))
    print(count)

