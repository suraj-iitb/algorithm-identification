n = int(input())
a = list(map(int,input().split()))

def counting_sort(A,k):
    B = []
    C = [0]*(k+1)

    for j in range(len(A)):
        C[A[j]] += 1

    for i in range(len(C)):
        while True:
            if C[i] != 0:
                B.append(i)
                C[i] -= 1
            else:
                break
    return B

result = counting_sort(a,max(a))
print(*result)
