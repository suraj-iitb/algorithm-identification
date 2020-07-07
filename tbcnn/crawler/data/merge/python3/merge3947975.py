num = 0
def marge_sort(array):
    global num
    if len(array) < 2: return array
    
    mid = len(array) // 2
    left = marge_sort(array[:mid])
    right = marge_sort(array[mid:])
    
    len_l, len_r = len(left), len(right)
    left += [float("inf")]
    right += [float("inf")]
    
    marray = [0] * (len_l + len_r)
    
    l, r = 0, 0
    for i in range(len_l + len_r):
        num += 1
        if left[l] <= right[r]:
            marray[i] = left[l]
            l += 1
        else:
            marray[i] = right[r]
            r += 1
        
    return marray

n = int(input())
a = list(map(int, input().split()))

print(" ".join(map(str, marge_sort(a))))
print(num)
