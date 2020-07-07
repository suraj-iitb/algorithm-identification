N = int(input())
S = list(map(int, input().split(" ")))
Exchange_Number_of_times = 0
for i in range(N):
    minj = i
    for j in range(i, N):
        if S[j] < S[minj]:
            minj = j
    if i != minj:
        S[i], S[minj] = S[minj], S[i]
        Exchange_Number_of_times += 1
print(' '.join(map(str,S)))
print(Exchange_Number_of_times)

