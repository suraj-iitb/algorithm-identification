n = int(input())
A = list(map(int, input().split()))
B = []
C = [0] * 10001
for x in A:
    C[x] += 1
for i, k in enumerate(C):
    B += [str(i)] * k
print(" ".join(B))
