def output_A(A):
    if len(A) == 1:
        print(A[0])
    else:
        for i in range(len(A)-1):
            print(f'{A[i]} ',end="")
        print(f'{A[i+1]}',)

N = int(input())
A = list(map(int,input().split()))

output_A(A)
for i in range(1,len(A)):
    key = A[i]
    j = i-1
    while j>=0 and A[j] > key :
        A[j+1] = A[j]
        j -= 1
    A[j+1] = key
    output_A(A)
