def main():
    # 個数を入力
    num = int(input())
    a = list(int(i) for i in input().split())

    print(*a)
    insertSort(a)

def insertSort(A):
    for i in range(1, len(A)):
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = v
        print(*A)

if __name__ == "__main__":
    main()
