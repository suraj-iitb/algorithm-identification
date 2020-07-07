def selectionSort(a):
    count = 0
    for i in range(len(a)):
        mini = i
        for j in range(i,len(a)):
            if a[j] < a[mini]:
                mini = j
        if i != mini:
            ret = a[i]
            a[i] = a[mini]
            a[mini] = ret
            count += 1
    print(" ".join(map(str,a)))
    print(count)
n = int(input())
a = list(map(int,input().split()))
selectionSort(a)
