
def selection_sort(array):
    A = array[:]
    count = 0
    for i in range(len(A)):
        mini = i
        for j in range(i, len(A)):
            if int(A[j]) < int(A[mini]):
                mini = j
        if i != mini:
            A[i], A[mini] = A[mini], A[i]
            count += 1

    return A, count

_, array = input(), input().split()

result, count = selection_sort(array)

print(' '.join(result))
print(count)
