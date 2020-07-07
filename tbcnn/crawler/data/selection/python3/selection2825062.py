def ssort(a,n):
    count = 0
    for i in range(n):
        mini = i
        for j in range(i, n):
            if a[mini]>a[j]:
                mini = j
        if i!=mini:
            a[i], a[mini] = a[mini], a[i]
            count+=1
    print(*a)
    print(count)
n= int(input())
a = [int(x) for x in input().split()]
ssort(a,n)

