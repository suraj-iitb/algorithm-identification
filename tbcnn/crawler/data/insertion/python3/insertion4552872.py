n = int(input())
a = list(map(int, input().split()))

def print_space(li):
    for i in range(len(li)-1):
        print(li[i], end=' ')
    else:
        print(li[-1])

def InsertionSort(li):
    print_space(li)
    for i in range(1, n):
        v = li[i]
        j = i - 1
        while j >= 0 and li[j] > v:
            li[j+1] = li[j]
            j -= 1
        else:
            li[j+1] = v
        print_space(li)
            

InsertionSort(a)


