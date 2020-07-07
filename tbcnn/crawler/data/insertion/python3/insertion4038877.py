def insertionSort(arr):
    for i in range(1, len(arr)): 
        v = arr[i] 
        j = i-1
        print(*arr)                                          
        while j >= 0 and v < arr[j] : 
            arr[j+1] = arr[j] 
            j -= 1
        arr[j+1] = v
        
    print(*arr)

n = int(input())
ls = list(map(int,input().split()))
insertionSort(ls)

