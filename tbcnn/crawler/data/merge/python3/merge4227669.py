# coding: utf-8
# Your code here!

INF = 10**10

def merge(A, left, mid, right):
    n1 = mid - left
    n2 = right - mid
    a1 = [A[i+left] for i in range(n1)]
    a2 = [A[i+mid] for i in range(n2)]
    a1.append(INF)
    a2.append(INF)
    
    a1_i = a2_i = 0
    
    for i in range(right-left):
        if a1[a1_i] <= a2[a2_i]:
            A[left+i] = a1[a1_i]
            a1_i += 1
        else:
            A[left+i] = a2[a2_i]
            a2_i += 1
    return right-left
    
def merge_sort(A, left, right):
    cnt = 0
    
    if left+1 < right:
        mid = (left + right) // 2
        cnt += merge_sort(A, left, mid)
        cnt += merge_sort(A, mid, right)
        
        cnt += merge(A, left, mid, right)
        
        #print('l={}, r={}, m={}'.format(left, right, mid))    
        #print(*A)
        
    return cnt

n = int(input())
S = [int(i) for i in input().split()]

cnt = merge_sort(S, 0, n)

print(*S)
print(cnt)

