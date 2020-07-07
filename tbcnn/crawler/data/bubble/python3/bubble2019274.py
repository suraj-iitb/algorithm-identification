def bubblesort(N, A):
    """Do BubbleSort"""
    m = 0
    flag = True
    while(flag):
        flag = False
        for i in range(N-1, 0, -1):
            if (A[i-1] > A[i]):
                tmp = A[i-1]
                A[i-1] = A[i]
                m += 1
                A[i] = tmp
                flag = True
    b = list(map(str, A))
    print(" ".join(b))
    print(m)

A = []
N = int(input())
s = input()
A = list(map(int, s.split()))
bubblesort(N, A)
