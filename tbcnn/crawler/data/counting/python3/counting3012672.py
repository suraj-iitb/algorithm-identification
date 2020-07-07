flg = 0
n = int(input())
l = list(map(int,input().split()))
bucket = [0]*10000
for i in range(n):
    bucket[l[i]] += 1
    if flg < l[i]:
        flg = l[i]
for i in range(flg):
    for j in range(bucket[i]):
        print(i,end = ' ')
for i in range(bucket[flg]-1):
    print(flg,end=' ')
print(flg)
