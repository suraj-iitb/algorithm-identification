length = int(input())
target = (int(n) for n in input().split(" "))
bucket = [0 for n in range(10001)]
for t in target:
    bucket[t] += 1
answer = []
for i, b in enumerate(bucket):
    answer += [i] * b
print(*answer)
