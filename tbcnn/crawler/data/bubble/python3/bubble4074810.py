def b_sort(A):
    flg = True
    swap = 0
    while flg:
        flg = False
        for j in range(len(A) - 1,0,-1):
            if A[j] < A[j-1]:
                A[j],A[j-1] = A[j-1],A[j]
                swap += 1
                flg = True
    return swap

if __name__=='__main__':
    N = int(input())
    A = list(map(int,input().split()))
    swap = b_sort(A)
    print(*A)
    print(swap)

