def bubble_sort(array):
    count = 0
    A = array[:]
    for i in range(len(A)):
        for j in range(1, len(A) - i):
            if int(A[j - 1]) > int(A[j]):
                count += 1
                A[j - 1], A[j] = A[j], A[j - 1]
    return A, count

_, array = input(), input().split()

result, count = bubble_sort(array)

print(' '.join(result))
print(count)
