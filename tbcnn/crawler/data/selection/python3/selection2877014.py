def selection_sort(a,n):
    count=0
    for i in range(n):
        ch=False
        minj=i
        for j in range(i,n):
            if a[j] < a[minj]:
                minj = j
                ch = True
        if(ch):
            count+=1
        a[i],a[minj] = a[minj],a[i]
    return count

if __name__ == "__main__":
    n=int(input())
    a=list(map(int,input().split()))
    count=selection_sort(a,n)
    print(*a)
    print(count)
