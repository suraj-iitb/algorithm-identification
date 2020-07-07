def list_print(A):
    ret = str(A[0])
    for i in range(1, len(A)):
        ret += " " + str(A[i])

    print(ret)
    return True


n = int(input())
A = list(map(int, input().split()))
list_print(A)
for i in range(1, n):
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j + 1] = A[j]
        j -= 1
    A[j + 1] = v

    list_print(A)
