def mergesort(n_list, left, right):
    if left + 1 < right:
        mid = math.ceil((left + right)/2)
        mergesort(n_list, left, mid)
        mergesort(n_list, mid, right)
        merge(n_list, left, mid, right)

def merge(n_list, left, mid, right):
    global c
    n1 = mid - left
    n2 = right - mid
    l_list = n_list[left:mid]
    r_list = n_list[mid:right]
    l_list.append(10e10)
    r_list.append(10e10)
    i = 0
    j = 0
    for k in range(left, right):
        c += 1
        if l_list[i] < r_list[j]:
            n_list[k] = l_list[i]
            i += 1
        else:
            n_list[k] = r_list[j]
            j += 1

        
        

import math
n = int(input())
n_list = list(map(int, input().split()))
c = 0
mergesort(n_list, 0, n)
print(" ".join(map(str, n_list)))
print(c)
