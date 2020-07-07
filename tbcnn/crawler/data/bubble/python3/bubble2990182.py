input()
arr = list(map(int, input().split()))
flag = False
count = 0
while not flag:
    flag = True
    for i in range(len(arr)-1):
        if arr[i] > arr[i+1]:
            count += 1
            flag = False
            t = arr[i+1]
            arr[i+1] = arr[i]
            arr[i] = t  
print(" ".join(map(str, arr)))
print(count)
