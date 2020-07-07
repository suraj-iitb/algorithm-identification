def insertion_sort(A):
    for i in range(1, len(A)):
        temp = A[i]
        j = i - 1
        while j >= 0 and A[j] > temp:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = temp
        print(' '.join(list(map(str,A))))

if __name__ == '__main__':
    n = int(input())
    l = list(map(int, input().split()))
    print(' '.join(list(map(str,l))))
    insertion_sort(l)
