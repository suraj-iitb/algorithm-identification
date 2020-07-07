# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_B&lang=jp
# Selection Sort: python3
#  2018.12.09 yonezawa

import sys
input = sys.stdin.readline


def selectionSort(l):
    cnt= min_i= 0
    for i in range(len(l)-1):
        min_i = i
        flg = False
        for j in range(i+1,len(l)):
            if l[min_i] > l[j]:
                min_i = j
                flg = True
        if flg == True:
            cnt += 1
            #print (l[i],l[min_i])
            (l[i],l[min_i]) = (l[min_i],l[i]) 
    return l,cnt

def main():
    n = int(input())
    l = list(map(int,input().split()))
    (ans,cnt) = selectionSort(l)
    print (*ans)
    print (cnt)
if __name__ == '__main__':
    main()

