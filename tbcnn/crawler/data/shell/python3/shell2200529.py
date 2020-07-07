N = int(input())
a = [int(input()) for i in range(N)]
f = []
x = 1
while x <= N:
    f.append(x)
    x = 3*x + 1
cnt = 0
g = f[::-1]

def insertionSort(a, N, g):
    global cnt
    for i in range(g, N):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j + g] = a[j]
            j -= g
            cnt += 1
        a[j + g] = v
  
m = len(g)    
for j in range(m):
    insertionSort(a, N, g[j])

print(m)
print(" ".join(map(str, g)))
print(cnt)
for i in range(N):
    print(a[i])
