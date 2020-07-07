n = int(input())
a = list(map(int, input().split()))
b = [0] * (n+1)
m = max(a)
c = [0] * (m+1)
for i in a:
    c[i] += 1
for j in range(1, m+1):
    c[j] = c[j] + c[j-1]
#print(c)
for k in reversed(a):
    #print(k)
    #print(b)
    b[c[k]] = k
    c[k] -= 1

for i in range(1,n):
    print(b[i], end=' ')
print(b[n])
