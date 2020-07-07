
import sys
sys.setrecursionlimit(10 ** 7)
read = sys.stdin.buffer.read
inp = sys.stdin.buffer.readline
def inpS(): return inp().rstrip().decode()
readlines = sys.stdin.buffer.readlines
MOD = 10 ** 9 + 7
INF = 1 << 60

# ---------------------------------------------------
# ---------------------------------------------------
# ---------------------------------------------------

def resolve():
    N = int(inp())
    A = list(map(int, inp().split()))
    print(*A)

    for i in range(1, N):
        v = A[i]
        j = i-1
        while j>=0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v
        print(*A)


if __name__ == '__main__':
    resolve()

