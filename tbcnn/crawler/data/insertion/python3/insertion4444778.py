def show (seqs):
    for i in range(len(seqs)):
        if i != len(seqs)-1:
            print(seqs[i], end = ' ')
        else :
            print(seqs[i])

num = int(input())
seqs = list(map(int,input().split()))

show(seqs)
for i in range(1,num):
    element = seqs[i]
    j = i-1
    while (j>=0 and seqs[j]>element):
        seqs[j+1] = seqs[j]
        j -=1
    seqs[j+1] = element
    show(seqs)
