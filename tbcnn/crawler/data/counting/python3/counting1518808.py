def CountingSort(A,B,k):
    C = []
    for i in range(0,k+1):
        C.append(0)
    for j in A:
        C[j] += 1
    for i in range(0,k+1):
        while(C[i] != 0):
            B.append(i)
            C[i] -= 1
B = []
n = int(input())
st = input()
A = list(map(int,st.split()))
max = 0
for x in A:
    if x > max:
        max = x
CountingSort(A,B,max)
for i in range(0,n-1):
    print(B[i],end=" ")
print(B[n-1])
