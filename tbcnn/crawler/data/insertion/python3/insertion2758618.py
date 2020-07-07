def insertion_sort(A):
    for i in range(1, len(A)):
        v = A[i]
        j = i - 1
        print(*A)
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            A[j] = v
            j -= 1
    return A

n = input()
A = [int(x) for x in input().split()]
print(*insertion_sort(A))

