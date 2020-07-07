def selection_sort(A):
    swap = 0
    for i in range(len(A)):
        minj = i
        for j in range(i,len(A)):
            if A[j] < A[minj]:
                minj = j
        if minj != i:
            A[i],A[minj] = A[minj],A[i]
            swap += 1
    return swap

if __name__=='__main__':
   N=int(input()) 
   A=list(map(int,input().split()))
   swap = selection_sort(A)
   print(*A)
   print(swap)
