a = int(input())
b = list(map(int,input().split()))

def bublesort(b,a):
    count =0
    for j in range(len(b)-1):
        for i in range(len(b)-1,0,-1):
            if b[i-1]>b[i]:
                b[i-1],b[i]=b[i],b[i-1]
                count +=1
    return count,b

A,B =bublesort(b,a)
print(*B)
print(A)


