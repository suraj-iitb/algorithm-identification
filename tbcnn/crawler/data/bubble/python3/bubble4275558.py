def bubbleSort(A, N):
    flag = True
    c = 0
    while flag:
        flag = False
        for j in range(N-1,0,-1):
            if A[j] < A[j-1]:
                A[j],A[j-1] = A[j-1],A[j]
                c += 1
                flag = True
    return A,c
num = int(input())
li1 = [int(e) for e in input().split()]
li2 = bubbleSort(li1,num)
print(*li2[0],sep=" ")
print(li2[1])
