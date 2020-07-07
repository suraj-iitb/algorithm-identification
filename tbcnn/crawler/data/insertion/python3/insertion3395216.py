def pres(data, N):
    for i in range(N):
        if i < N-1:
            print('%d '%data[i], end='')
        else:
            print(data[i])
        
def ins_sort(data, N):
    for i in range(1, N):
        flag = data[i]
        j = i-1
        while j>=0 and data[j]>flag:
            data[j+1] = data[j]
            j-=1
        data[j+1] = flag
        pres(data, N)
    
    
N = int(input())
data  = list(map(int, input().split()))

pres(data, N)
ins_sort(data, N)

