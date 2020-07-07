#!/usr/bin/env python

def bubbleSort(A, N):
    swap_count = 0

    flag = True
    while flag:
        flag = False
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                swap_count += 1
                flag = True
    ans = " ".join(map(str, A))
    print(ans)
    print(swap_count)

def main():
    size = int(input())
    line = list(map(int, input().split()))
    bubbleSort(line, size)

if __name__ == '__main__':
    main()
