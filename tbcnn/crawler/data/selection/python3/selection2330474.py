#ALDS1_2-B Sort 1 - Selection Sort
def selectionSort(A,N):
    c=0
    for i in range(N):
        minj = i
        j=i
        while j<N:
            if(int(A[j])<int(A[minj])):
                minj = j
            j+=1
        if(i!=minj):
            A[i],A[minj]=A[minj],A[i]
            c+=1
    return c

N=int(input())
A=input().split()
c=selectionSort(A,N)
S=""
for i in range(N-1):
    S+=A[i]+" "
S+=str(A[-1])
print(S)
print(c)
