import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")

def main():
    n = int(input())
    aa = list(map(int, input().split()))
    ans=0
    for i in range(n):
        min_j=i
        for j in range(i+1,n):
            if aa[j]<aa[min_j]:min_j=j
        if min_j!=i:
            aa[i],aa[min_j]=aa[min_j],aa[i]
            ans+=1
    print(*aa)
    print(ans)

main()

