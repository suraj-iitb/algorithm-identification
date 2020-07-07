n = int(input())
numbs = list(map(int,input().split()))
print(' '.join(map(str,numbs)))
for i in range(1,len(numbs)):
    key = numbs[i]
    j = i-1
    while j >=0 and numbs[j] > key:
        numbs[j+1] = numbs[j]
        j -= 1
    numbs[j+1] = key
    print(' '.join(map(str,numbs)))
