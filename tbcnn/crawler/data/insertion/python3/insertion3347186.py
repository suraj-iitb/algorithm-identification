n = int(input())
A = list(map(int, input().split()))
i=1
print(" ".join(list(map(str, A))))
while i < n:
    v = A[i]
    j = i-1
    while j >= 0 and A[j]>v:
        A[j+1]=A[j]
        j-=1
    A[j+1]=v
    print(" ".join(list(map(str,A))))
    i+=1

