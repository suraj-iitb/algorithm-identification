N = int(input())
A = list(map(int, input().split(' ')))
if len(A) != N:
    raise ValueError('N個の整数を入力してください。')
elif N < 1 or N > 100:
    raise ValueError('1から100までの整数を入力してください')

frag = 1
count = 0

def print_num(A):
    for i in range(len(A)):
        if i != N-1:
            print(A[i], end=' ')
        else:
            print(A[i])
    
while frag:
    frag = 0
    for j in reversed(range(1, N)):
        if A[j]<A[j-1]:
            v = A[j]
            A[j] = A[j-1]
            A[j-1] = v
            frag = 1
            count += 1
            
print_num(A)
print(count)

