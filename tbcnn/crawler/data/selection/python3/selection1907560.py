n = int(input())
array = list(map(int,input().split()))
count = 0;

for i in range(n-1):
    mini = i
    for j in range(i,n):
        if array[j] < array[mini]:
            mini = j
    if mini != i :
        array[i],array[mini] = array[mini],array[i]
        count += 1

print(" ".join(list(map(str,array))))
print(count)
