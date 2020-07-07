def print_list(A):
    print(" ".join(list(map(str, A))))

def main():
    N = int(input())
    A = list(map(int, input().split()))

    print_list(A)

    for i in range(1, N):
        store_v = A[i]
        
        j = i - 1
        while j >= 0 and A[j] > store_v:
            A[j + 1] = A[j]
            j -= 1

        A[j+1] = store_v

        print_list(A)

main()
