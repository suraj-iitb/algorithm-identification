_ = input()
a = list(map(int, input().split()))

count = 0
for i in range(len(a)):
    minj = i
    for j in range(i+1, len(a)):
        #print('taiget {} in list {}'.format(a[i], a[j:]))
        if a[j] < a[minj]:
            minj = j
    #print('change[{}] to [{}]'.format(a[i], a[minj]))
    if a[i] != a[minj]:
        a[i], a[minj] = a[minj], a[i]
        count += 1

print(' '.join(map(str, a)))
print(count)

