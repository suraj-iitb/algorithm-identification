N = int(input())
A = list(map(int,input().split()))
print(' '.join([str(a) for a in A]))

for i in range(1,N):
    key = A[i]
    j = i-1
    # j=0で先頭まで来たらもう比較しない
    while j>=0 and A[j] > key:
        # より小さい項と比較する
        A[j+1] = A[j]
        
        j -= 1
    # keyの位置は確定したので代入(while抜ける前にj-=1されているのでA[j+1])
    A[j+1] = key
    print(' '.join([str(a) for a in A]))
