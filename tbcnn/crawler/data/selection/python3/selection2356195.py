# coding=utf-8

def print_list(X):
    first_flag = True
    for val in X:
        if first_flag:
            print_line = str(val)
            first_flag = False
        else:
            print_line = print_line + ' ' + str(val)
    print(print_line)

def selection_sort(A, N):
    counter = 0

    for i in range(N):
        min_j = i

        for j in range(i, N):
            if A[j] < A[min_j]:
                min_j = j

        if i != min_j:
            A[i], A[min_j] = A[min_j], A[i]
            counter += 1

    print_list(A)
    print(counter)

N = int(input())
A = list(map(int, input().split()))

selection_sort(A, N)
