def InsertionSort(a:list, n:int):
    for i in range(0,n):
        key = a[i]
        j = i - 1
        while( j >= 0 and a[j] > key):
            a[j+1] = a[j]
            j = j - 1
        a[j+1] = key
        print(" ".join(map(str,a)))
    return a

def main():
    n = int(input())
    a = list(map(int, input().split()))
    InsertionSort(a, n)


if __name__ == "__main__":
    main()

