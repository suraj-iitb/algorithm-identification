def s():
 input()
 C=[0]*10001
 for a in map(int,input().split()):C[a]+=1
 B=[];i=0
 for k in C:B+=[str(i)]*k;i+=1
 print(' '.join(B))
if'__main__'==__name__:s()
