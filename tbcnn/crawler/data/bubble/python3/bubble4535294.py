def bubblesort(A,N):
    count = 0
    for j in range(N):
        for i in range(N-1):
            if A[i] > A[i+1]:
                A[i],A[i+1] = A[i+1],A[i]
                count += 1

    return A,count

def bubblesort_re(A,N):
    count = 0
    #A[i] > A[i+1]の状態がある→交換する必要がある：flag = True
    #交換する必要が無いとbreak→値の無駄な比較をしない
    flag = True
    while flag:
        flag = False
        for i in range(N-1):
            if A[i] > A[i+1]:
                A[i],A[i+1] = A[i+1],A[i]
                count += 1
                flag = True

    return A,count

if __name__ == '__main__':
    N = int(input())
    A = [int(i) for i in input().split()]
    ans,count = bubblesort_re(A,N)
    for i in range(N):
        if i != N - 1:
            print(ans[i],end = " ")
        else:
            print(ans[i])
    print(count)

