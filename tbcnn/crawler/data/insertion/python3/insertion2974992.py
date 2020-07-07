N = int(input())
arr = list(map(int, input().split()))

for i in range(len(arr)):
    for j in range(i,0,-1):
        if(arr[j] < arr[j-1]):
            temp = arr[j]
            arr[j] = arr[j-1]
            arr[j-1] = temp
        else:
            continue
    print(' '.join(map(str,arr)))
