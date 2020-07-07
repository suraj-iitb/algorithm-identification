kazu=int(input())
A=[int(i) for i in input().split()]
# kazu=6
# A=[5,2,4,6,1,3]

j=0
for i in range(kazu - 1):
    print(A[i], end=" ")
print(A[kazu-1])

for i in range(1,kazu):
    v=A[i]
    j=i-1

    while j>=0 and A[j] >v:
        A[j+1]=A[j]
        j =j -1
        A[j+1]=v
    for i in range(kazu-1):
        print(A[i],end=" ")
    print(A[kazu-1])
