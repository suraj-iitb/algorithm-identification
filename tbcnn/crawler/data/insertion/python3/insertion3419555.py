Num_factor = int(input())
N = list(map(int, input().split()))


for i in range(int(Num_factor)):
    v = N[i]
    j = i - 1
    while(j >= 0 and N[j] > v):
        N[j+1] = N[j]
        j -= 1
    N[j+1] = v
    print(" ".join(map(str,N)))
