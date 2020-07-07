INF = int(1e4)
def countingSort(A, k):
    n = len(A)
    output = [INF for _ in range(n+1)]
    count = [0 for _ in range(k)]
    for i in range(n):
        count[A[i]] += 1

    for i in range(1, k):
        count[i] = count[i] + count[i-1] 

    for i in reversed(range(n)): 
        output[count[A[i]]] = A[i]
        count[A[i]] -= 1

    return output[1:]

def main():
    n = int(input())
    a = [int(i) for i in input().split()]
    ans = countingSort(a, INF)
    for i in range(n):
        if i == n-1:
            print(ans[i])
        else:
            print(ans[i], end=' ')
main()
