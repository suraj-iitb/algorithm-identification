def main():
    n = int(input())
    a = list(map(int,input().split()))
    res = 0
    for i in range(n):
        minj = i
        for j in range(i+1,n):
            if a[j] < a[minj]:
                minj = j
        if minj != i:res+=1
        a[i],a[minj] = a[minj],a[i]
    print (' '.join(map(str,a)))
    print (res)

if __name__ == '__main__':
    main()


