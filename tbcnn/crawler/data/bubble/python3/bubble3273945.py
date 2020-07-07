# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A&lang=jp
# Bubble Sort: python3
#  2018.12.05 yonezawa

import sys
input = sys.stdin.readline


def bubbleSort(l):
    cnt = 0    
    flg = True
    while True:
        flg = False
        for i in range(len(l)-1):
            if l[i] > l[i + 1]:
                (l[i],l[i+1]) = (l[i+1],l[i])
                cnt += 1
                flg = True
        if flg == False:
            break
    return l,cnt

def main():
    n = int(input())
    l = list(map(int,input().split()))
    (ans,cnt) = bubbleSort(l)
    print (*ans)
    print (cnt)
if __name__ == '__main__':
    main()

