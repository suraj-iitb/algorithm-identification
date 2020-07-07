n = int(input())
l = list(map(int,input().split()))

count = 0
dec = 0

is_reverse = True
while is_reverse:
    is_reverse = False
    
    for i in range(n-1-dec):
        if l[i] > l[i+1]:
            l[i] , l[i+1] = l[i+1], l[i]
            is_reverse = True
            count += 1
    
    dec += 1

print(' '.join(map(str,l)))
print(count)
