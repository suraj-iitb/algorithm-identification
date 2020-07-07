cnt=0
def merge_sort(S):
    l=len(S)
    mid=int(l/2)
    Left=S[0:mid]
    Right=S[(mid):l]
    global cnt
    
    if l>=2:
        merge_sort(Left) and merge_sort(Right)
    

    Left.append(float('inf'))
    Right.append(float('inf'))

    p=0
    q=0
    for i in range(l):
        if Left[p]<Right[q]:
            S[i]=Left[p]
            p+=1
        else:
            S[i]=Right[q]
            q+=1
    if l!=1 :
        cnt+=l
    
    return S


n=int(input())
S=list(map(int,input().split()))
merge_sort(S)
print(*S)
print(cnt)
