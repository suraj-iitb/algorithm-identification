N=int(input())
number=list(map(int,input().split()))

print(' '.join(map(str,number)))
for i in range(1,N):
    strage=number[i]
    j=i-1
    for j in range(0,i)[::-1]:
        if number[j]>strage:
            number[j+1]=number[j]
            j-=1
            number[j+1]=strage
    print(' '.join(map(str,number)))

