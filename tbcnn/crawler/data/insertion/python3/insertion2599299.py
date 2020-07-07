def main():

    n = int(input())
    arr = list(map(int,input().split()))

    for i in range(1, len(arr)):
        j = i - 1
        v = arr[i]
        print(' '.join(map(str,arr)))
        while j >= 0 and arr[j] > v:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = v 
    print(' '.join(map(str,arr)))


main()
