N = int(input())
number = list(map(int,input().split()))

flag = 1
i = 0
count = 0
while flag==1:
    flag = 0
    for j in range(i+1,len(number))[::-1]:
        if number[j] < number[j-1]:
            temp  = number[j]
            number[j] = number[j-1]
            number[j-1] = temp
            flag = 1
            count += 1
    i += 1


print(" ".join(map(str,number)))
print (count)
