n = int(input())
nlist = list(map(int, input().split()))
def BubbleSort(C, n):
    c = 0
    for i in range(n-1):
        for w in range(i+1, n):
            j = n-w+i
            if (C[j] < C[j-1]):
                a = C[j]
                C[j] = C[j-1]
                C[j-1] = a
                c += 1
    C.append(c)
BubbleSort(nlist, n)
for i in range(n):
    if (i == n-1):
        print('{}'.format(nlist[i]), end = '')
    else : 
        print('{}'.format(nlist[i]), end = ' ')
print()
print(nlist[-1])
