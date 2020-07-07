# coding: utf-8
# Your code here!

def counting_sort(A, MAX=10010):
    count = [0] * MAX
    for a in A:
        count[a] += 1
    
    for i in range(1, len(count)):
        count[i] = count[i-1] + count[i]
    
    b = [None]*len(A)
    for i in range(len(A)-1, -1, -1):
        
        ai = A[i]
        ci = count[ai]
        b[ci-1] = ai
        #b[count[A[i]]] = A[i]
        count[ai] -= 1
    
    return b

n = int(input())
a = [int(i) for i in input().split()]

b = counting_sort(a)

print(*b)

