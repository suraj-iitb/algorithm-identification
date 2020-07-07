def insertion_sort(A):
    for i in range(1,len(A)):
        print(*A)
        key = A[i]
        #/* insert A[i] into the sorted sequence A[0,...,j-1] */
        j = i - 1
        while j >= 0 and A[j] > key:
            A[j+1] = A[j]
            j-=1
        A[j+1] = key
 
if __name__=='__main__':
   n=int(input()) 
   A=list(map(int,input().split()))
   insertion_sort(A)
   print(*A)
