n = int(input())
l = list(map(int,input().split()))
def insertionSort(l,n):
    ans = map(str,l)
    print(" ".join(ans))
    for i in range(1,n):
        v = l[i]
        j = i - 1
        while j>=0 and l[j]>v:
            l[j+1]=l[j]
            j -= 1
        l[j+1] = v
        ans = map(str,l)
        print(" ".join(ans))
insertionSort(l,n)

