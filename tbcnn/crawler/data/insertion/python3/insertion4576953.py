# coding: utf-8
# Your code here!

N = int(input())
arr = list(map(int,input().split()))
#print(N,arr)
print(" ".join(str(x) for x in arr))
def insertionSort(N,arr):
    for i in range(1,N):
        v = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > v:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = v
        
        #arr = " ".join(arr)
        print(" ".join(str(x) for x in arr))
    return arr
    

        
ans = insertionSort(N,arr) 
