import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")

def main():
    n = int(input())
    aa = list(map(int, input().split()))
    for i in range(n):
        a = aa.pop(i)
        for j in range(i - 1, -1, -1):
            if aa[j] <= a:
                aa.insert(j + 1, a)
                break
        else:
            aa = [a] + aa
        print(*aa)

main()

