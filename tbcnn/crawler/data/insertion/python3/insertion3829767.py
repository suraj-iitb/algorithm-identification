def insertion_sort(A,N):
    for i in range(1,N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        print(' '.join(map(str,A)))
    
    
n = int(input())
test = list(map(int,input().split()))

print(' '.join(map(str,test)))
insertion_sort(test,n)

