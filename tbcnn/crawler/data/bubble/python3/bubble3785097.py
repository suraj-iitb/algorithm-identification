n = int(input())
A = list(map(int,input().split(" ")))

def bubbleSort(n,A):
    c = 0
    flag = True
    while flag:
        flag = False
        for j in reversed(range(1,n)):
            if A[j] < A[j-1]:
                c+=1
                tmp = A[j]
                A[j] = A[j-1]
                A[j-1] = tmp
                flag = True
    return (A,c,)


R,C = bubbleSort(n,A)
print(" ".join(["{0["+ str(i) + "]}" for i in range(n)]).format(R))
print(C)
