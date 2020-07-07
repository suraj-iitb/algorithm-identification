def main():
    N = int(input())
    A = list(map(int,input().split()))
    flag = True
    count = 0
    while flag:
        flag = False
        for i in range(N-1,0,-1):
            if A[i] < A[i-1]:
                count += 1
                A[i], A[i-1] = A[i-1], A[i]
                flag = True
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
