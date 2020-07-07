N = int(input())
a = [int(i) for i in input().split()]
frag = 1
i = 0
count = 0
while frag:
    frag = 0
    for j in range(N-1,i,-1):
        if a[j] < a[j-1]:
            a[j], a[j-1] = a[j-1], a[j]
            count += 1
        frag = 1
        
    i += 1

print(" ".join(map(str, a)))
print(count)
