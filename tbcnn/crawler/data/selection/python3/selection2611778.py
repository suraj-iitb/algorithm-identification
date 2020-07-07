n=int(input())
a=[int(i) for i in input().split(" ")]
x=0

for i in range(n):
    mi = i
    for j in range(i, n):
        if a[j] < a[mi]:
            mi = j
    
    if i != mi:
        x += 1
        a[i], a[mi] = a[mi] , a[i]

print(" ".join([str(i) for i in a]))
print(x)
