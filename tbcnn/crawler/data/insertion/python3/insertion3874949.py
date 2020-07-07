from sys import stdin

n = int(stdin.readline().rstrip())
li = list(map(int,stdin.readline().rstrip().split()))

li2 = []
for i in range(len(li)):
    s = li.pop(0)
    li2.append(s)
    li2.sort()
    ans = li2+li
    print(' '.join(map(str, ans)))
