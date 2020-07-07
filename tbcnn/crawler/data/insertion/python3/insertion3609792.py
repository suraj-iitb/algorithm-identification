def insertion_sort(A, N):
    for i in range(1, N):
        v = A[i]
        j = i - 1
        # print('[start] i:', i, 'j:', j, 'v:', v)
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        # print('i:', i, 'v:', v, 'to:', j+1 ,A)
        print(*A)

N = int(input())
A = list(map(int, input().split()))
print(*A)
insertion_sort(A, N)
