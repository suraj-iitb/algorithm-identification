#insertion sort

n = int(input())
A = list(map(int,input().split()))

print(*A)

for i in range(1,n):
    j = i
    while(j > 0):
        if A[j-1] > A[j]:
            A[j-1],A[j] = A[j],A[j-1] #SWAP
            j -= 1
        else:
            break
    
    print(*A)
