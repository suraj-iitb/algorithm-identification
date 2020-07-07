N = int(input())
aa = list(map(int, input().split()))
for i in range(N):
    tmpl = sorted(aa[:i+1]) + aa[i+1:]
    print(" ".join(map(str,tmpl)))
