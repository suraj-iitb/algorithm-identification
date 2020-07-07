N = int(input())
A = map(int, input().split())

C = [0] * 10001
for a in A:
  C[a] += 1

B = []
for i, c in enumerate(C):
  B.extend([i] * c)
print(*B)
