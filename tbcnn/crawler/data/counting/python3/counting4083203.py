def Counting_Sort(A,k):
    c = [0]*(k+1)
    b = [0]*n
    for a in A:
        c[a]+=1
    for i in range(1,k+1):
        c[i] = c[i] + c[i-1]
    
    for a in A:
        rank = c[a]
        b[rank-1] = a
        c[a] -= 1
    print(*b)

n = int(input())
a = list(map(int, input().split()))
k = max(a)+1
Counting_Sort(a,k)

