
def print_result(A, n):
    for i in range(n):
        if i > 0:
            print(' ', end='')
        print(A[i], end='')
    print('\n', end='')


def insertion_sort(A, n):

    for i in range(1, n):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        print_result(arr, n)


n = eval(input())

arr = [eval(x) for x in input().split()]
print_result(arr, n)
insertion_sort(arr, n)

