def show(nums):
    for i in range(len(nums)):
        if i!=len(nums)-1:
            print(nums[i],end=' ')
        else:
            print(nums[i])

def selection_sort(A, N):
    num = 0
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        if minj != i:
            A[i], A[minj] = A[minj], A[i]
            num += 1

    show(A)
    print(num)



if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split(' ')))
    selection_sort(A, N)

