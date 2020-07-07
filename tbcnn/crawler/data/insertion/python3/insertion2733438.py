def InsertionSort(A, N):
    ans = ' '.join(map(str, A)) + '\n'
    i = 1
    while i < N:
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = v
        ans += ' '.join(map(str, A)) + '\n'
        i += 1
    return ans[:-1]

n = int(input())
A = list(map(int, input().split(' ')))
ans = InsertionSort(A, n)
print(ans)
