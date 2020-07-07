def bubble_sort(A):
    flag = True
    swap = 0
    while flag:
        flag = False
        for j in range(len(A)-1,0,-1):
            if A[j] < A[j-1]:
                A[j],A[j-1] = A[j-1],A[j]
                swap += 1
                flag = True
    return swap
 
if __name__=='__main__':
   N=int(input()) 
   A=list(map(int,input().split()))
   swap = bubble_sort(A)
   print(*A)
   print(swap)
