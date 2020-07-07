def bubbleSort(A, N):
    flag = True
    swap_cnt = 0
    while flag:
        flag = False
        for j in range(N-1, 0, -1):
            if A[j] < A[j - 1]:
                A[j], A[j - 1] = A[j - 1], A[j]
                swap_cnt += 1
                flag = True
    return swap_cnt, A

def run():
    n = int(input())
    a = list(map(int, input().split()))
    c, a = bubbleSort(a,n)
    print(' '.join([str(i) for i in a]))
    print(c)

if __name__ == '__main__':
    run()
