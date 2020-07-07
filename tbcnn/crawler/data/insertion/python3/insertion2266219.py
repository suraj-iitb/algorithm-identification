#!/usr/bin/env python
size = int(input())
line = list(map(int, input().split()))

def insertionSort(A, N):
    ans = " ".join(map(str, line))
    print(ans)
    for i in range(1, N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        ans = " ".join(map(str, line))
        print(ans)

def main():
    insertionSort(line, size)

if __name__ == '__main__':
    main()
