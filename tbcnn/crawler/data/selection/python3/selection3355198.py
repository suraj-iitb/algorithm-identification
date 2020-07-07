N = int(input())
I = list(map(int, input().split()))
cnt = 0
for i in range(N):
    min_index = i
    for j in range(i, N):
        if (I[j] < I[min_index]):
            min_index = j
    if (min_index != i):
        tmp = I[i]
        I[i] = I[min_index]
        I[min_index] = tmp
        cnt += 1

print(str(I).replace(',','').replace('[','').replace(']',''))
print(cnt)
