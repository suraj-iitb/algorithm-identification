def insertionSort(arr): 
  
    # Traverse through 1 to len(arr) 
    for i in range(1, len(arr)): 
  
        key = arr[i] 
        j = i - 1
        
        while j >=0 and key < arr[j] : 
                arr[j+1] = arr[j] 
                j -= 1
        arr[j+1] = key
        
        print(' '.join(map(str, numbers)))

_ = input()
numbers = list(map(int, input().split()))
print(' '.join(map(str, numbers)))
insertionSort(numbers)
