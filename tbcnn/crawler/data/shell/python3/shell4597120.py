from math import floor
def insertionSort(A,n,g):
    global cnt
    for i in range(g,n):
        v=A[i]
        j=i-g
        while j>=0 and A[j]>v:
            A[j+g]=A[j]
            j-=g
            cnt+=1
        A[j+g]=v
        
def shellSort(A,n):
    global G
    for i in G:
        insertionSort(A,n,i)
cnt=0
N=int(input())
A=[int(input())for i in range(N)]
G=[1]
for i in range(99):
    if N<1+3*G[-1]:
        break
    G.append(1+3*G[-1])
G.reverse()
shellSort(A,N)
print(len(G)," ".join(list(map(str,G))),cnt,sep="\n")
for i in A:
    print(i)
