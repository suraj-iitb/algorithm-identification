N = int(input())
A =  list(map(int, input().split())) 

s_count = 0
i = 0

while i < N:

    min_j = i
    j = i

    while j < N:

        if A[j] < A[min_j]:

            min_j = j

        j += 1

    A[i], A[min_j] = A[min_j], A[i]

    if i != min_j :
        s_count += 1

    i += 1

s = ''

for x in A:

    s = s + str(x) + ' '

print(s.rstrip())
print(s_count)

