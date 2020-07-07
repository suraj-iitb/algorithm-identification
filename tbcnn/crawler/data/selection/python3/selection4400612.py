n = int(input())
R = list(map(int,input().split()))

def trace():
    for i in range(len(R)):
        if i != len(R) - 1:
            print(R[i],end=' ')
        else:
            print(R[i])

count = 0
for i in range(0,n):
    minj = i
    for j in range(i,n):
        if R[j] < R[minj]:
            minj = j

    R[i],R[minj] = R[minj],R[i]
    if i != minj:
        count += 1
    


trace()
print(count)
