N = int(input())
a = input().split()
b = [int(n) for n in a]


for i in range(N):
    v = b[i]
    j = i-1
    while j>=0 and b[j]>v:
        b[j+1] = b[j]
        j = j-1
        b[j+1] = v
    print(" ".join([str(n) for n in b]))
