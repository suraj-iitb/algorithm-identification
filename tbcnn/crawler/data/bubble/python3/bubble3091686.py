n = 0
dat = []

swap = 0


def input_file():
    global n, A
    f = open('input', mode='r')
    n = int(f.readline())
    *A, = map(int, f.readline().split(' '))


def input_cmd():
    global n, A
    n = int(input())
    *A, = map(int, input().split(' '))


input_cmd()

# input_file()

ans = 0
for _ in range(n):
    for j in range(n - 1):
        if A[j + 1] < A[j]:
            A[j], A[j + 1] = A[j + 1], A[j]
            ans += 1

# ans = 0
# for _ in range(n):
#     for j in range(n - 1):
#         if A[j + 1] < A[j]:
#             A[j], A[j + 1] = A[j + 1], A[j]
#             ans += 1

print(*A)
print(ans)
