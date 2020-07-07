def bubble_sort(ls):
    flag=True
    i=0
    ch=0
    while flag:
        flag = False
        for j in reversed(range(i+1,len(ls))):
            if ls[j] < ls[j-1]:
                ls[j],ls[j-1] = ls[j-1],ls[j]
                flag = True
                ch += 1
        i += 1
    return ch

if __name__ == "__main__":
    ls=[]
    n=int(input())
    ls = list(map(int,input().split()))
    ch=bubble_sort(ls)
    for i in range(len(ls)):
        if i == len(ls)-1:
            print(ls[i])
        else:
            print(ls[i],end=" ")
    print(ch)
