N = int(input())
A = list(map(int,input().split()))

count = 0
for a in range(len(A)-1):
    index_min = A[(a+1):].index(min(A[(a+1):]))+a+1
    # print(f'{min(A[a+1:])} {index_min}')
    if A[a] > A[index_min]:
        A[a],A[index_min] = A[index_min],A[a]
        count += 1
        # print(*A)
print(*A)
print(count)

