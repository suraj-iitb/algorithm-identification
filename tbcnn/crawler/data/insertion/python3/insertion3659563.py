N = int(input())
A_INPUT = list(map(int, input().split()))

A = A_INPUT[:]

import bisect
for i in range(N):
    sorted_list = A[:i]
    v = A[i]
    unsorted_list = A[i+1:]
    bisect.insort(sorted_list, v)
    
    
        
    A = sorted_list + unsorted_list
    print(' '.join(map(str,A)))
    
