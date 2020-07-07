#計数ソート
maxx = 2000001;
maxnum = 10010;

n=int(input())
A=[int(x) for x in input().split()]  
A.insert(0,0) 
B=[-1 for x in range(n)]
C=[0 for x in range(maxnum)]



for a in A[1:]:
    C[a]+=1
for i in range(1,maxnum): # 累加和
    C[i]+=C[i - 1]
    
for j in range(1,n+1):
    B[C[A[j]]-1]=A[j]
    C[A[j]]-=1

lens=len(B)    
for i in range(0,lens-1):
    print(B[i],end=' ')
print(B[lens-1])
