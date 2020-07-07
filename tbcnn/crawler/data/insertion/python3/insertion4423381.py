def insertion_sort(N, A):
    print(*A)
    for i in range(1, N):
        key = A[i]
        j = i - 1
        while j >= 0 and A[j] > key:
            A[j+1] = A[j]
            j -= 1
        A[j + 1] = key
        print(*A)  

def main():
    N = int(input())
    A = list(map(int, input().split()))
    insertion_sort(N, A)

#insertion_sort(6, [5, 2, 4, 6, 1, 3])
main()

