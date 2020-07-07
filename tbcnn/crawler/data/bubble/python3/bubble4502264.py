n = int(input())
R = [int(x) for x in input().split()]#リスト内包表記

def bubble_sort(r):
    flag=True
    i=0
    count=0
    while flag:
        flag=False
        for i in range(n-1,i,-1):#iは1でとまらないとi-1が-1となってしまう
            if r[i]<r[i-1]:
                r[i],r[i-1]=r[i-1],r[i]#swap
                count+=1
                flag=True#入れ替える条件があって初めてtrueになる
    print(*r)
    print(count)

bubble_sort(R)
