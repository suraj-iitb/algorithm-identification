def selection(A,N):
    count = 0
    for i in range(0,N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        if i != minj:
            A[i],A[minj]=A[minj],A[i]
            count += 1
    return count 

n = int(input())
a = list(map(int,input().split()))
count=selection(a,n)
print(' '.join(map(str,a)))
print(count)
