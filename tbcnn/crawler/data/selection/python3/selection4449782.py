num = int(input())
seqs = list(map(int,input().split()))
count = 0
for i in range(num):
    minIndex = i
    for j in range(i,num):
        if seqs[j] < seqs[minIndex]:
            minIndex = j
    if minIndex != i:
        seqs[i],seqs[minIndex]=seqs[minIndex],seqs[i]
        count+=1

print(" ".join(map(str, seqs)))
print(count)

