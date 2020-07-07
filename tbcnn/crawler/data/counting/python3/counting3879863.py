import sys
input = sys.stdin.readline

def countingSort(A, k):
    n = len(A)
    C = [0] * (k+1)
    for i in A:
        C[i] += 1
    for i in range(1, k+1):
        C[i] += C[i-1]
    B = [0] * n
    A.reverse
    for i in A:
        B[C[i]-1] = i
        C[i] -= 1
    return B
def main():
    n = int(input())
    A = list(map(int, input(). split()))
    B = countingSort(A, 10000)
    print(' '.join(list(map(str, B))))

if __name__ == '__main__': main()
