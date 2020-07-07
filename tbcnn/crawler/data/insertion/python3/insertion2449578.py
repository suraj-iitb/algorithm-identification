n = int(input())
k = [int(i) for i in input().split()]

for i in range(n):
    v = k[i]
    j = i-1
    while j >= 0 and k[j] > v:
        k[j+1] = k[j]
        j-=1
    k[j+1] =v
    print(' '.join(map(str, k)))
    
