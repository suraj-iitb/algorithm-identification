n = int(input())
a = list(map(int,input().split()))

flag = True
judge = True
count=0

while flag:
    for i in range(n-1,0,-1):
        if a[i] < a[i - 1]:
            a[i],a[i - 1] = a[i - 1], a[i] #swap
            count+=1
    if sorted(a) == a: flag = False

print(' '.join(map(str,a)))
print(count)

