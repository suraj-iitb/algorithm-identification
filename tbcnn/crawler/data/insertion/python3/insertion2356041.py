#coding: utf-8

def print_list(X):
    first_frag = True
    for val in X:
        if first_frag:
            print_line = str(val)
            first_frag = False
        else:
            print_line = print_line + ' ' + str(val)
    print(print_line)

N = int(input())
A = list(map(int, input().split()))

print_list(A)

for i in range(1, N):
    tmp_val = A[i]
    j = i - 1
    while (j >= 0) and (tmp_val < A[j]):
        A[j+1] = A[j]
        j -= 1
    A[j+1] = tmp_val

    print_list(A)
