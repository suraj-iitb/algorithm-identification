def show(nums):
    for i in range(len(nums)):
        if i!=len(nums)-1:
            print(nums[i],end=' ')
        else:
            print(nums[i])


def intersetion_sort(A, N):
    for i in range(N):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        show(A)
    return A


if __name__ == '__main__':
    N = int(input())
    A = list(map(int, input().split(' ')))
    intersetion_sort(A, N)

