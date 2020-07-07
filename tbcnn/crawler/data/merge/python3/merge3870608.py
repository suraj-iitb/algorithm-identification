#import time
count=0
def merge(A,left,mid,right):
    global count
    L=A[left:mid]+[2**30]
    R=A[mid:right]+[2**30]

    i=0
    j=0
    for k in range(left,right):
        count+=1
        if L[i]<=R[j]:
            A[k]=L[i]
            i+=1
        else:
            A[k]=R[j]
            j+=1


def mergeSort(A,left,right):
    if left+1 < right:
        mid = int((left+right)/2)
        mergeSort(A,left,mid)
        mergeSort(A,mid,right)
        merge(A,left,mid,right)


#start = time.time()

n=int(input())
s=list(map(int,input().split()))
count=0
mergeSort(s,0,n)

print(s[0],end='',sep='')
for i in range(1,n):
    print(" ",s[i],end='',sep='')
print()

print(count)

#end=time.time()-start
#end*=1000
#print ("Time:{0}".format(end) + "[m_sec]")

