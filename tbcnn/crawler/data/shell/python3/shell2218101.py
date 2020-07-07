import random

# n = 10
# A = [random.randint(1, 100) for i in range(20)]
n = int(input())
A = [int(input()) for i in range(n)]
cnt = 0

def insertion_sort(list, step):
    n = len(list)
    for i in range(step, n):
        temp = list[i]
        j = i
        while j >= step and list[j - step] > temp:
            list[j] = list[j - step]
            j -= step
            global cnt
            cnt += 1
        list[j] = temp
    return list

def shell_sort(list):
    n = len(list)
    
    G = []
    step = 1
    while step <= n:
        G.append(step)
        step = 3*step + 1
    print(len(G))
    for g in sorted(G, reverse=True):
        print(g, end=' ')
    print('\n', end='')

    for i in sorted(range(len(G)), reverse=True):
        list = insertion_sort(list, G[i])
    return list

shell_sort(A)
print(cnt)

for i in A:
    print(i, end='\n')
