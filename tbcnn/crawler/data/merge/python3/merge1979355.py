def merge(targ,first,mid,last):
    left = targ[first:mid] + [10 ** 9 + 1]
    right = targ[mid:last] + [10 ** 9 + 1]

    leftcnt = rightcnt = 0
    global ans
    for i in range(first,last):
        ans += 1
        #print(left,right,left[leftcnt],right[rightcnt],targ,ans)
        if left[leftcnt] <= right[rightcnt]:
            targ[i] = left[leftcnt]
            leftcnt += 1
        else:
            targ[i] = right[rightcnt]
            rightcnt += 1

def mergesort(targ,first,last):

    if first +1 >= last:
        pass
    else:
        mid = (first + last) // 2
        mergesort(targ,first,mid)
        mergesort(targ,mid,last)
        merge(targ,first,mid,last)


ans = 0
num = int(input())
targ = [int(n) for n in input().split(' ')]
mergesort(targ,0,num)
print(" ".join([str(n) for n in targ]))
print(ans)
