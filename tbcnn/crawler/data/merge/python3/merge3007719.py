#ALDS1_5-B Merge Sort
from collections import deque

def merge(A,B):
    ans = [0]*(len(A)+len(B))
    count=i=j=0
    A+=[10**9+1]
    B+=[10**9+1]
    for k in range(len(ans)):
        if A[i]<B[j]:
            ans[k]=A[i]
            i+=1
        else:
            ans[k]=B[j]
            j+=1
        count+=1
    return (ans,count)

n = int(input())
S = [int(i) for i in input().split()]
div = deque([S])
mer = deque()
count = 0
while(len(div)>0):
    d = div.pop()
    if(len(d)>2):
        mid = len(d)//2
        div.appendleft(d[:mid])
        div.appendleft(d[mid:])
    elif(len(d)==2):
        if d[0] > d[1]:
            mer.appendleft(d[::-1])
        else:
            mer.appendleft(d)
        count+=2
    else:
        mer.appendleft(d)
        
while(len(mer)>1):
    A = mer.popleft()
    B = mer.popleft()
    ret = merge(A,B)
    mer.append(ret[0])
    count+=ret[1]
    
ans = ""
for i in ret[0]:
    ans += str(i) + " "
print(ans[:-1])
print(count)
