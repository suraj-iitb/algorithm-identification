N = int(input())
a = list(map(int, input().strip().split()))
rev = 0
counter = 0
while(rev >= 0):
    for i in range(1, N):
        if(a[i-1] > a[i]):
            a[i-1], a[i] = a[i], a[i-1]
            rev += 1
            counter += 1
    if(rev == 0):
        for j in range(0, N-1):
            print(a[j], end=" ")
        print(a[N-1])
        print(counter)
        break
    rev = 0

