from sys import stdin
#stdin = open("input.txt")

def bubbleSort(A, N):
    flag = True
    cnt = 0
    while flag:
        flag = False
        for j in range(N-1, 0, -1):
            if A[j] < A[j-1]:
                A[j], A[j-1] = A[j-1], A[j]
                cnt += 1
                flag = True
    return cnt

if __name__ == "__main__":
    N = int(stdin.readline())
    A = [int(item) for item in stdin.readline().split()]
    cnt = bubbleSort(A, N)
    print(*A)
    print(cnt)
