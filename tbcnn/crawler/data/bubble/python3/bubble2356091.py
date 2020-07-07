#coding: utf-8

def print_list(X):
    first_flag = True
    for val in X:
        if first_flag:
            print_line = str(val)
            first_flag = False
        else:
            print_line = print_line + ' ' + str(val)
    print(print_line)

def bubble_sort(A, N):
    #print_list(A)
    #flag: ???????????????????????????True???????´?
    flag = True
    counter = 0

    while flag:
        flag = False
        for j in range(1, N):
            if A[j] < A[j-1]:
                tmp_val = A[j]
                A[j] = A[j-1]
                A[j-1] = tmp_val

                flag = True
                counter += 1
        #print_list(A)
    print_list(A)
    print(counter)

N = int(input())
A = list(map(int, input().split()))

bubble_sort(A, N)
