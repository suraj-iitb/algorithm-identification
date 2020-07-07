
n = int(input())
number = list(map(int,input().split()))
count = 0
for i in range(1,n + 1):
    for j in range(1,i):
        
        if number[i - j] < number[i - j - 1]:
            number[i - j],number[i - j - 1] = number[i - j - 1],number[i - j]
            count += 1
number = list(map(str,number))
print(" ".join(number))
print(count)
