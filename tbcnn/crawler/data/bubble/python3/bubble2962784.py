N = int(input())
S = list(map(int, input().split(" ")))
Exchange_Number_of_times = 0
flag = True
while flag:
    flag = False
    for j in range(N - 1, 0, -1):
        f = j - 1
        if S[j] < S[f]:
            S[j], S[f] = S[f], S[j]
            flag = True
            Exchange_Number_of_times += 1
print(' '.join(map(str,S)))
print(Exchange_Number_of_times)
