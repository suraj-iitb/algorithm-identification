def selection(A, N):
    count = 0
    for i in range(0, N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        if i != minj:
            A[i], A[minj] = A[minj], A[i]
            count += 1
    return A, count



if __name__ == "__main__":
    N = int(input())
    A = [int(i) for i in input().split()]

    A, count = selection(A, N)
    print (*A)
    print (count)
