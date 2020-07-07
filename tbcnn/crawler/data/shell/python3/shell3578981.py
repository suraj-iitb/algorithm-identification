def pr(sequence):
    string = ''
    for i in sequence[:-1]:
        string += str(i) + ' '
    string += str(sequence[-1])
    print(string)

def insertion_sort(a,n,g,cnt):
    for i in range(g,n):
        key = a[i]
        j = i-g
        while (j >=0) and (a[j] > key):
            a[j+g] = a[j]
            j = j-g
            cnt = cnt + 1
        a[j+g] = key
    return a,cnt

n = int(input())
a = [int(input()) for _ in range(n)]


cnt = 0
# m = min(n-1,100)
# if n == 1:m=1
# g = [i for i in range(m,0,-1)]
# g = 1
if n !=1:
    g = [1]
    while g[0] < n:
        g.insert(0, 3*g[0]+1)
    g.pop(0)
else:
    g = [1]
m = len(g)

for i in range(m):
    a,cnt = insertion_sort(a,n,g[i],cnt)


print(m)
pr(g)
print(cnt)
for i in a:
    print(i)
