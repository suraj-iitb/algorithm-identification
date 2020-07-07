def main():
    N = int(input())
    A = list(map(int,input().split()))
    cnt = 0

    for i in range(N):
        temp = i
        minj = A[i]
        for j in range(i+1,N):
            if A[j] < minj:
                minj = A[j]
                temp = j

        if temp != i:
            temp2 = A[i]
            A[i] = A[temp]
            A[temp] = temp2
            cnt += 1

    print(' '.join(map(str,A)))
    print(cnt)


main()

