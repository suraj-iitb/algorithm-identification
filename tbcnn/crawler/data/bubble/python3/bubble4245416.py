def show(nums):
    for i in range(len(nums)):
        if i!=len(nums)-1:
            print(nums[i],end=' ')
        else:
            print(nums[i])

def bubble_sort(A, N):
    num_exchange = 0
    FLAG = 1
    while FLAG:
        FLAG = 0

        for j in reversed(range(1, N)):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                num_exchange += 1
                FLAG = 1
    show(A)
    print(num_exchange)

if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split(' ')))
    bubble_sort(A, N)


