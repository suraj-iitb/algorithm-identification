a = int(input())
b = list(map(int,input().split()))
print(" ".join(list(map(str,b))))
for i in range(1,a):
    v = b[i]
    j = i -1
    while j >=0 and b[j] > v:
        b[j+1] = b[j]
        j -= 1
        b[j+1] = v
    print(" ".join(list(map(str,b))))

