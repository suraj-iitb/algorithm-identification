num = int(input())
arr = list(map(int,input().split()))
print(" ".join(list(map(str,arr))))
def isn(A,N):
    for i in range(1,N):
        v = A[i]
        j = i-1
        while j >= 0 and A[j] >v:
            A[j+1] = A[j]
            j -=1
        A[j+1] = v
        print(" ".join(list(map(str,arr))))

isn(arr,num)

