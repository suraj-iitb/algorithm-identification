n = int(input())
A = list(map(int, input().split()))

result_list = []
result_list.append(A[:])

for i in range(1,len(A)):
    key = A[i]
    j = i -1
    while j >= 0 and A[j] > key:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = key
    result_list.append(A[:])

for i in range(n):
    if i > len(result_list):
        print(' '.join(str(n) for n in result_list[-1]))
    print(' '.join(str(n) for n in result_list[i]))
