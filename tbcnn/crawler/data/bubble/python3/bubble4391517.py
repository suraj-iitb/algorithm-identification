# Problem - バブルソート

def bubbleSort(A, N):
    sort_count = 0
    flag = 1
    while flag:
        flag = 0
        for j in range(N-1, 0, -1):
            if A[j]<A[j-1]:
                tmp = A[j]
                A[j] = A[j-1]
                A[j-1] = tmp
                sort_count += 1
                flag = 1
    return A, sort_count

# input
N = int(input())
a_list = list(map(int, input().split()))

# output
ans_list, ans_count = bubbleSort(a_list, N)
print(" ".join(list(map(str, ans_list))))
print(ans_count)

