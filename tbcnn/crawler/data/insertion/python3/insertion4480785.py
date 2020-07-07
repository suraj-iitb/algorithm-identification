N = int(input())
A = list(map(int, input().split()))

def insertion_sort(A):
    for idx, target in enumerate(A[1:]):
        j = idx
        while j >= 0 and A[j] > target:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = target
        disp(A)

def disp(A):
    for i in A[:-1]:
        print(i, end=" ")
    print(A[-1])

disp(A)
insertion_sort(A)
