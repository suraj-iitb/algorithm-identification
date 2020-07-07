import sys
 
def isort(a, n, g):
    global cnt
    for i in range(g, n):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j + g] = a[j]
            j -= g
            cnt += 1
        a[j + g] = v
 
# input data
n = int(sys.stdin.readline())
a = []
for i in range(n):
    a.append(int(sys.stdin.readline()))
 
# determine m, g
g = [1]
m = 1
while True:
    x = 3 * g[m - 1] + 1
    if x >= n: break
    g.append(x)
    m += 1
g = g[::-1]
 
# 1 output m
print(m)
# 2 output g
print(' '.join(map(str, g)))
 
# sort it
cnt = 0
for i in range(m):
    isort(a, n, g[i])
 
# 3 output cnt
print(cnt)
# 4 output sorted a
print('\n'.join(map(str, a)))
