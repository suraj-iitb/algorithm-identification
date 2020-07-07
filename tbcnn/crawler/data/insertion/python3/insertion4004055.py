N = int(input())
A = list(map(int, input().split(' ')))

print(*A)
for i in range(1, N):
    V = A[i]
    insert_index = i
    for j in reversed(range(i)):
        if A[j] > V:
            insert_index = j
    A.pop(i)
    A.insert(insert_index, V)
    print(*A)
