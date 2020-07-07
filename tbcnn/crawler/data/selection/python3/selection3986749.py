n = int(input())
ary = list(map(int, input().split()))
cnt = 0

for i in range(n-1):
  minj = i #0
  for j in range(i, n):
    if (ary[j] < ary[minj]):
      minj = j
  ary[i], ary[minj] = ary[minj], ary[i]
  if (i != minj): cnt += 1

print(' '.join(map(str, ary)))
print(cnt)

