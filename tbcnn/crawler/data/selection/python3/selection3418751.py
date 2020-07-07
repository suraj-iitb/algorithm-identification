N = int(input())
A = input()
B = A.split()
total = 0
for i in range(N) :
    mini = int(i)
    for j in range(i, N) :
        if int(B[j]) < int(B[mini]) :
            mini = int(j)
    if mini != int(i) :
        B[i], B[mini] = B[mini], B[i]
        total += 1
print(" ".join(B))
print(total)
