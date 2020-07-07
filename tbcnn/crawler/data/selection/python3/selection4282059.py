N = int(input())
table = list(map(int,input().split()))
count = 0
for i in range(N):
    minj = i
    for j in range(i,N):
        if table[j] <table[minj]:
            minj = j#最小の数がある位置
    table[i],table[minj] = table[minj],table[i]
    if i != minj:
        count += 1

print(" ".join(map(str,table)))
print(count)

