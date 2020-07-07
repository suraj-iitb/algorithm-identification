def main():
    N = int(input())
    A = list(map(int,input().split()))
    count = 0
    for i in range(N):
        minj = i
        for j in range(i,N):
            if A[j] < A[minj]:
                minj = j
        count += (i != minj)
        A[i], A[minj] = A[minj], A[i]

    print(" ".join(map(str,A)))
    print(count)


if __name__ == "__main__":
    import os
    import sys
    if len(sys.argv) > 1:
        if sys.argv[1] == "-d":
            fd = os.open("input.txt", os.O_RDONLY)
            os.dup2(fd, sys.stdin.fileno())
            main()
    else:
        main()
