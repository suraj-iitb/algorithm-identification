def bubblesort(N,A):
    flag = 1
    counta = 0
    while flag:
        flag = 0
        for j in range(N-1,0,-1):
            if A[j] < A[j-1]:
                A[j],A[j-1] = A[j-1],A[j]
                flag = 1
                counta += 1
    print(" ".join(map(str,A)))
    print(counta)

bubblesort(int(input()),list(map(int,input().split())))

            
