n = int(input())
a = [int(i) for i in input().split()]

for i in range(len(a)):
    v = a[i]
    j = i - 1
    while j >= 0 and a[j]>v:
        a[j+1] = a[j]
        j-=1
    a[j+1]=v
    print(" ".join([str(i) for i in a]))
