N = int(input())
A = input()
B = A.split()
flag = 1
total = 0
while flag :
    flag = 0
    for i in range(N-1, 0, -1) :
        if int(B[i]) < int(B[i-1]) :
            B[i], B[i-1] = B[i-1], B[i]
            flag = 1
            total += 1
print(" ".join(B))
print(total)
