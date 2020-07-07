def show(A):
    output = ""
    for i in range(len(A)):
        output += str(A[i]) + " "
    print(output[:-1])

def insertionsort(A, N):
    for i in range(1, N):
        show(A)
        A[:i+1] = sorted(A[:i+1])
    show(A)
    
N = int(input())
A = list(map(int, input().split())) 

insertionsort(A, N)
