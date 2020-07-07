# coding: utf-8
# Here your code !
S = int(input())
N = list(map(int,input().split()))
count=0
def bubblesort(n,s):
    global count
    flag = 1
    while flag:
        flag = 0
        for i in range(s-1,0,-1):
            key = n[i]
            if n[i]<n[i-1]:
                n[i]=n[i-1]
                n[i-1]=key
                count+=1
                flag=1
    print(" ".join(list(map(str,n))))
    print(count)
        
bubblesort(N,S)
