def selection(l):
    count = 0
    for i in range(len(l)):
        minj = i
        for j in range(i,len(l)):
            if l[j] < l[minj]:
                minj = j
        if l[i] > l[minj]:
            a = l[i]
            l[i] = l[minj]
            l[minj] = a
            count += 1
    ans_l = map(str,l)
    return ans_l,count
n = int(input())
l = list(map(int,input().split()))
ans_l,count = selection(l)
print(' '.join(ans_l))
print(count)

