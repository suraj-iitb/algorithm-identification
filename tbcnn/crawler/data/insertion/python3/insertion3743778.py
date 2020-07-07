N = int(input())
A = input().split()
A = [int(i) for i in A]

#listの要素を出力
def print_list_val(A):
    s = ''
    for i in range(len(A)):
        s = s + str(A[i])
        if i != len(A) - 1:
            s += " "
    print(s)
    
for i in range(N):
    v = A[i]
    j = i - 1
    while( j >= 0 and A[j] > v):
        A[j+1] = A[j]
        j -= 1
    A[j+1] = v
    print_list_val(A)
