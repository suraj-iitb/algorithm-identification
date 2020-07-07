def bubbleSort(l):
    k = 1
    count = 0
    for j in range(len(l)-1):
        for i in range(len(l)-k):
            if l[i] > l[i+1]:
                a = l[i]
                l[i] = l[i+1]
                l[i+1] = a
                count += 1
        k += 1

    ans_l = map(str,l)
    return ans_l,count

n = int(input())
l = list(map(int,input().split()))
ans_l,ans_count = bubbleSort(l)
print(' '.join(ans_l))
print(ans_count)

