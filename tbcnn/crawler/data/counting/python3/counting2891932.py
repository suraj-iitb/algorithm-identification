n = int(input())
A = list(map(int, input().split())) # 入力配列
B = [0 for i in range(n)] # 出力配列
C = [0 for i in range(10001)] # カウンタ配列

for a in A:
    C[a] += 1

for i in range(1, len(C)):
    C[i] = C[i] + C[i - 1]

for a in reversed(A):
    B[C[a] - 1] = a
    C[a] -= 1

print(' '.join(map(str, B)))

