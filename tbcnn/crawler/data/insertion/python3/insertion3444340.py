import bisect
n=int(input())
a=list(map(int,input().split()))
print(' '.join(map(str,a)))
for i in range(1,n):
    a_n=a.pop(i)
    insert_index = bisect.bisect_left(a[:i],a_n)
    a.insert(insert_index,a_n)
    print(' '.join(map(str,a)))
