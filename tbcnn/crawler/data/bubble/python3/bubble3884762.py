from sys import stdin

n = int(stdin.readline().rstrip())
li = list(map(int,stdin.readline().rstrip().split()))

frag = 1
point = 0
while frag == 1:
    frag = 0
    for i in range(n-1,0,-1):
        if li[i] < li[i-1]:
            li[i],li[i-1] = li[i-1],li[i]
            frag = 1
            point += 1
print(' '.join(map(str, li)))
print(point)
