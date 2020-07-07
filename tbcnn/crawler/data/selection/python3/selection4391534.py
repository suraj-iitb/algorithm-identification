# Problem - 選択ソート

def selection_sort(A, N):
    sort_count = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j]<A[minj]:
                minj = j
        if not minj==i:
            tmp = A[i]
            A[i] = A[minj]
            A[minj] = tmp
            sort_count += 1
    return A, sort_count

# input
N = int(input())
a_nums = list(map(int, input().split()))

# initialization
ans_list, ans_count = selection_sort(a_nums, N)
print(" ".join(list(map(str, ans_list))))
print(ans_count)

