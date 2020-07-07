def main():
    N = int(input())
    A = tuple(map(int, input().split()))

    a = list(A)
    ans, n = bubbleSort(a, N)
    print(*ans, sep=' ')
    print(n)

def bubbleSort(a, n):
    j = 0
    flag = 1
    while flag:
        flag = 0
        for i in range(1, n):
            if a[i] < a[i-1]:
                a[i], a[i-1] = a[i-1], a[i]
                flag = 1
                j += 1
    return a, j

main()
