N = int(input())
num_list = list(map(int,input().split()))

for n in range(N):
    if n == N-1:
        print(num_list[n])
    else:
        print(num_list[n],end=" ")
        
for i in range(1,N):
    v = num_list[i]
    j = i-1
    while j >= 0 and num_list[j] > v:
        num_list[j+1] = num_list[j]
        j -= 1
    num_list[j+1] = v
    for n in range(N):
        if n == N-1:
            print(num_list[n])
        else:
            print(num_list[n],end=" ")
