N = int(input())
I = list(map(int, input().split()))

print(str(I).replace(',','').replace('[','').replace(']',''))
for i in range(1, N):
    v = I[i]
    j = i - 1 
    while (j >= 0 and I[j] > v):
        I[j+1] = I[j]
        j -= 1
    I[j+1] = v
    print(str(I).replace(',','').replace('[','').replace(']',''))


