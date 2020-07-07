n = int(input())
A = list(map(int, input().split()))

def trace():
    for i in range(len(A)):
        if i != len(A) - 1:
            print(A[i],end=' ')
        else:
            print(A[i])
        


for i in range(len(A)):
    v = A[i]
    j = i - 1
    while j >= 0 and A[j] > v:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = v

    trace()
