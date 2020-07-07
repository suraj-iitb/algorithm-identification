N = int(input())
A = list(map(int,input().split()))

count = 0
for b in range(len(A)-1):
    for a in range(0,len(A)-1-b):
        if A[-a-1] < A[-a-2]:
            A[-a-1],A[-a-2] = A[-a-2],A[-a-1]
            count += 1

print(' '.join(list(map(str,A))))
print(count)

