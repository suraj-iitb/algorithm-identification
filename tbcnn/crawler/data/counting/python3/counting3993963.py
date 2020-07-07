MAX = 10000

def bucket_sort(A):
    count_array = [0] * MAX
    B = [0] * len(A)
    for a in A:
        count_array[a] += 1

    for i in range(1, MAX):
        count_array[i] = count_array[i] + count_array[i-1]

    for a in A[::-1]:
        B[count_array[a]-1] = a
        count_array[a] -= 1
    return B

if __name__ == "__main__":
    n = int(input())
    *A, = map(int, input().split())
    # A = [0] + A
    print(*bucket_sort(A))
    


