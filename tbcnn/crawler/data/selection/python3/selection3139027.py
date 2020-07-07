import math
n = int(input())
cnt = 0
num = list(map(int, input().split()))
for i in range(n):
    _min = i
    for j in range(i,n):
        if num[j] < num[_min]:
            _min = j
    if i != _min:
        num[i], num[_min] = num[_min], num[i]
        cnt+=1
print(" ".join(map(str,num)))
print(cnt)
