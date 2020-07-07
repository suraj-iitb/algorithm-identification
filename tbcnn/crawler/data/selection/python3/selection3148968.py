n = int(input())
listA = list(map(int, input().split()))
i=0
count =0
while i < n:
    minj =i
    j=i
    while j < n:
        if listA[j] < listA[minj]:
            minj=j
        j+=1
    if i!=minj:
        count+=1
    listA[i], listA[minj] = listA[minj], listA[i]
    i+=1

print(" ".join(map(str, listA)))
print(count)
