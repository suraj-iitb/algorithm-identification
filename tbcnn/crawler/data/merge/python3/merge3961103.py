def m(S, left, mid, right):
  global count
  L = S[left:mid]
  R = S[mid:right]
  L.append(1000000000)
  R.append(1000000000)
  i = 0
  j = 0
  for k in range(left,right):
    count = count + 1
    if L[i] <= R[j]:
      S[k] = L[i]
      i = i + 1
    else:
      S[k] = R[j]
      j = j + 1

def ms(S,left,right):
  if (left+1) < right:
    mid = (left+right)//2
    ms(S, left, mid)
    ms(S, mid, right)
    m(S, left, mid, right)

n = int(input())
S = [int(x) for x in input().split()]
left = 0
right = n
count = 0

ms(S,left,right)

for i in range(n):
  if i != (n-1):
    print(S[i], end = " ")
  else:
    print(S[i])
print(count)

