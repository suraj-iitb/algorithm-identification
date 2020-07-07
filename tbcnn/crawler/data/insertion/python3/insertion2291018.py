size = int(input())
element = list(map(int,input().split()))
print(" ".join(map(str,element)))


for i in range(1,len(element)):
    v = element[i]
    j = i-1
    while j >=0 and element[j] > v:
        element[j+1] = element[j]
        j -=1
        element[j+1] = v
    print(" ".join(map(str,element)))
