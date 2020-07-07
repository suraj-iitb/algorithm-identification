def CountingSort(arr_size, in_arr, out_arr, maximum):

    c = [0] * (maximum + 1)
    for j in range(arr_size):
        c[in_arr[j]] += 1
    for i in range(1, maximum + 1):
        c[i] += c[i - 1]
    for j in range(arr_size - 1, -1, -1):
        out_arr[c[in_arr[j]]] = in_arr[j]
        c[in_arr[j]] -= 1

n = int(input())
A = list(map(int, input().split()))
B = [0] * (n + 1)
CountingSort(arr_size=n, in_arr=A, out_arr=B, maximum=max(A))
print(' '.join(map(str, B[1:])))
