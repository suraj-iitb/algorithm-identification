def selectionSort(a,n):
    cnt = 0
    for i in range(n-1):
        minj = i
        for j in range(i+1,n):
            if a[j] < a[minj]:
                minj = j

        if i != minj: 
            temp = a[minj]
            a[minj] = a[i]
            a[i] = temp
            cnt += 1
    print(" ".join(map(str,a)))
    print(cnt)

n = int(input())
a = list(map(int,input().split()))

selectionSort(a,n)
