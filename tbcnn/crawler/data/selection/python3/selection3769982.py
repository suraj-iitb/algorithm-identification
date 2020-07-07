n = int(input())
selection=list(map(int,input().split()))
count = 0

for i in range(len(selection)):
    minj = i
    for j in range (i,len(selection)):
        if selection[j] < selection[minj]:
            minj = j
    if i != minj:
        count = count+1      
        selection[i],selection[minj] = selection[minj],selection[i]
print(*selection)
print(count)
