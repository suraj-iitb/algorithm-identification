def sort(A):
    global c
    c=0 
    for i in range(0,len(A)-1):
        selection(A,i)
        
    return A

def selection(A,i):
    global c
    min=i
    for j in range(i+1,len(A)):
        if A[min]>A[j]:
            min=j
            
            
    A[i],A[min]=A[min],A[i]
    if not A[i]==A[min]:
        c+=1
    
    
n=int(input())
A=list(map(int,input().split()))

sort(A)
print(' '.join(list(map(str,A))))
print(c)

