N  = int(input())

table = list(map(int,input().split()))

swap_count = 0
for i in range(N-1):
    for k in range(N-1,i,-1):
        if table[k]<table[k-1]:
            table[k],table[k-1] = table[k-1],table[k]
            swap_count+=1

print(" ".join(map(str,table)))
print(swap_count)
