# 3.2
# input
N = int(input())
#a = [(input()) for i in range(N)]
a = list(map(int, input().split())) # "1 2 3"??¨??\???
print(" ".join(map(str, a)))

for i in range(1, N):
    tmp = a[i]
    j = i - 1
    while j >= 0 and a[j] > tmp:
        a[j + 1] = a[j]
        j -= 1
    
    a[j + 1] = tmp
    print(" ".join(map(str, a)))
