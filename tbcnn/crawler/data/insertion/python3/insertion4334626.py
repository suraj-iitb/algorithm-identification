def insertionSort(A):
    for i in range(len(A)):
        v = A[i]
        j = i-1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        for i in range(len(A)):
            if i == len(A)-1:
                print(A[i],end="\n")
            else:
                print(A[i],end=" ")

def main():
    N = int(input())
    A = list(map(int,input().split()))
    insertionSort(A)


if __name__ == "__main__":
    main()
