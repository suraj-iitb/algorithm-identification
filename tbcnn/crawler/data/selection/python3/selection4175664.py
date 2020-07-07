a = int(input())
b = list(map(int,input().split()))
A = []


def selectionSort(b,a):
    count = 0
    for i in range(len(b)-1):
        mini = i
        for j in range(i+1,len(b)):
            if b[mini]>b[j]:
                mini = j
        if b[mini]!=b[i]:
            b[i],b[mini]=b[mini],b[i]
            count += 1
    return b,count

A,B = selectionSort(b,a)
print(*A)
print(B)
