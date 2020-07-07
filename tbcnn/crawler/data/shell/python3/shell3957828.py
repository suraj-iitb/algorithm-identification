#1  insertionSort(A, n, g)
#2      for i = g to n-1
#3          v = A[i]
#4          j = i - g
#5          while j >= 0 && A[j] > v
#6              A[j+g] = A[j]
#7              j = j - g
#8              cnt++
#9          A[j+g] = v
#10
#11 shellSort(A, n)
#12     cnt = 0
#13     m = ?
#14     G[] = {?, ?,..., ?}
#15     for i = 0 to m-1
#16         insertionSort(A, n, G[i])
cnt = 0
def insertion_sort(a, n, g):
    global cnt
    for i in range(g, n):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j+g] = a[j]
            j = j -g
            cnt += 1
        a[j+g] = v

n = int(input())
a = [int(input()) for i in range(n) ]


def shell_sort(a, n):

    g = [1]
    for i in range(99):
        if n < 1 + 3*g[-1]:
            break
        g.append(1 + 3*g[-1])
    m = len(g)
    print(m)
    
    g.reverse()
    print(*g)
    for i in range(0, m):
        insertion_sort(a, n, g[i])
    
    print(cnt)
    return a


shell_sort(a, n)
print(*a, sep="\n")
