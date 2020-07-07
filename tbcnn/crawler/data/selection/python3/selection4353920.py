N = int(input())
number = list(map(int,input().split()))

count = 0
for i in range(0,len(number)):
    mini = i
    for j in range(i,len(number)):
        if number[j] < number[mini]:
            mini = j
    if mini != i: count += 1
    temp = number[i]
    number[i] = number[mini]
    number[mini] = temp


print(" ".join(map(str,number)))
print (count)
