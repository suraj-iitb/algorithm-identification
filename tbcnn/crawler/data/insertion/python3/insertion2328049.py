#ALDS1_1-A
def print_A(A,N):
    stri = ""
    for i in range(N-1):
        stri+=str(A[i])+" "
    stri+=str(A[N-1])
    print(stri)

def insertionSort(A,N):
    for i in range(N-1):
        v=A[i+1]
        j=i
        while j>=0 and A[j]>v:
            A[j+1]=A[j]
            j-=1
        A[j+1]=v
        print_A(A,N)

N=int(input())
A=[int(x) for x in input().split()]
print_A(A,N)
insertionSort(A,N)
