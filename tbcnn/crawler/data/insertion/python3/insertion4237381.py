n = int(input())
a = list(map(int,input().split()))
print(" ".join(map(str,a)))
def insertsort(m,b):
    j = 1
    while j <= m - 1:
        for t in range(0,j):
            if b[t] > b[j]:
                b[t],b[j] = b[j],b[t]
        j += 1
        print(" ".join(map(str,b)))

insertsort(n,a) 


