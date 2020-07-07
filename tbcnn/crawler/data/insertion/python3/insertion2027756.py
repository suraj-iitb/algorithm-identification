n = int(input())
num = list(map(int, input().split()))

    
print(" ".join(map(str, num)))
for i in range(len(num)-1):
    key = num[i+1]
    j = i 
    while j >= 0 and num[j] > key:
        num[j+1] = num[j]
        j -= 1
    num[j+1] = key
    print(" ".join(map(str, num)))
