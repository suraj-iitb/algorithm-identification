n = int(input())
A = list(map(int,input().split()))
print(' '.join(map(str, A)))
'''
for i in range(n):
    print(A[i], end=' ')
print('')
'''
for i in range(1, n):
    v = A[i]
    j = i - 1
    while j >=0 and A[j] > v:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = v
    '''
    for i in range(n):
        print(A[i], end=' ')
    print('')
    '''
    print(' '.join(map(str, A)))

