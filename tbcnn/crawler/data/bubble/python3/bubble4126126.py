def bubblesort(a,n):
    count = 0
    for i in range(n):
        for j in reversed(range(i+1,n)):
            if a[j] < a[j-1]:
                a[j-1],a[j] = a[j],a[j-1]
                count += 1
    print(" ".join(map(str,a)))
    print(count)
N = int(input())
A = [int(s) for s in input().split()]
bubblesort(A,N)

