N = int(input())
S = list(map(int, input().strip().split()))

for i in range(1, N+1):
    tmp = S[:i]
    tmp.sort()
    sroted_list = tmp + S[i:]
    str_list =[str(j) for j in sroted_list]
    print(' '.join(str_list))

