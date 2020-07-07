n = int(input())
a = list(map(int, input().split()))


def bubbleSort(A, N):
    change = 0
    flag = True
    while flag:
        flag = False
        for j in reversed(range(1, N)):
            #print(j, N)
            if A[j] < A[j-1]:
                A[j-1], A[j] = A[j], A[j-1]
                flag = True
                change += 1
                #print(A,j)
    return A, change

result, change_n = bubbleSort(a, n)


print (" ".join(map(str,result)))
print(change_n)

