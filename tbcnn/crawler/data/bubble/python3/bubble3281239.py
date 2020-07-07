def printer(A):
    ret = str(A[0])
    for i in range(1, len(A)):
        ret += " " + str(A[i])
    print(ret)
    return True


def bubblesort(A):
    ret = 0
    flag = True
    num = len(A)
    while flag is True:
        flag = False
        for i in reversed(range(1, num)):
            if A[i - 1] > A[i]:
                tmp = A[i - 1]
                A[i - 1] = A[i]
                A[i] = tmp
                flag = True
                ret += 1
        # num -= 1
    return ret


n = int(input())
A = list(map(int, input().split()))

ans = bubblesort(A)
# print(A)
printer(A)
print(ans)
