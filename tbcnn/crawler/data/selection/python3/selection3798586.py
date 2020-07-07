def getInput():
    n = int(input())
    a = [int(i) for i in input().split(" ")]
    return n, a

def swap(x, y):
    v = x
    x = y
    y = v
    return x, y

def selectionSort(n, a):
    cnt = 0
    for i in range(n):
        id_min = i
        for j in range(i+1, n):
            if a[j] < a[id_min]:
                id_min = j
        if id_min != i:
            a[i], a[id_min] = swap(a[i], a[id_min])
            cnt += 1
    print(" ".join([str(i) for i in a]))
    print(cnt)
    return

n, a = getInput()
selectionSort(n, a)

