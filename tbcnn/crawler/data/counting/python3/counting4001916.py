import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")

def main():
    n=int(input())
    aa=list(map(int, input().split()))
    aa.sort()
    print(*aa)
main()

