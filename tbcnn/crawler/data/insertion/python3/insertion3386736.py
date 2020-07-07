N = int(input()) #number of elements
seq = list(map(int,input().split()))
print(' '.join([str(i) for i in seq]))
for i in range(1,N):
    key = seq[i]
    j = i-1
    while j>=0 and seq[j]>key:
        seq[j+1] = seq[j]
        j -= 1
    seq[j+1] = key
    print(' '.join([str(k) for k in seq]))

