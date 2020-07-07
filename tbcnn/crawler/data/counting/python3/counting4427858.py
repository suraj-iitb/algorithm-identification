N =int(input())
A = list(map(int,input().split()))
COUNT = [0]*10000

def cnt_sort(A):
    res = [""] * len(A)
    for a in A:
        COUNT[a]+=1
    for i in range(1,len(COUNT)):
        COUNT[i] = COUNT[i] + COUNT[i-1]
    for a in A:
        res[COUNT[a]-1] = str(a)
        COUNT[a] -=1
    return res

print(" ".join( cnt_sort(A)))
