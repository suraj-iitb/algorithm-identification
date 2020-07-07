n = int(input())
a = list(map(int,input().split()))
print(" ".join(map(str,a)))
for i in range(1,n):
    for j in range(i):
        if a[i] > a[i-j-1]:
            temp = a.pop(i)
            a.insert(i-j,temp)
            break
        elif j == i - 1:
            temp = a.pop(i)
            a.insert(0,temp)
    print(" ".join(map(str,a)))
