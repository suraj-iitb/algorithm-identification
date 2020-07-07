n = int(input())
A = []
for i in range(n):
    A.append(int(input()))

# list G
m = 0
G = []
G.append(int(1))

while True:
  m += 1
  x = G[m-1]*3 + 1
  if x <= n and m < 100:
      G.append(x)
  else:
      break
G.reverse()

def iSort(A,n,g,cnt):
    for i in range(g,n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v
    return cnt

def sSort(A,n,G,m):
    cnt = 0
    for i in range(m):
        cnt = iSort(A,n,G[i],cnt)
    return cnt

print(m)
print(*G)
print(sSort(A,n,G,m))
for i in range(n):
    print(A[i])
