def main():
    N = int(input())
    values = list(map(int,input().split()))
    for i in range(1,N):
        print(" ".join(map(str,values)))
        v = values[i]
        j = i - 1
        while 0 <= j and v < values[j]:
            values[j+1] = values[j]
            j -= 1
        values[j+1] = v
    print(" ".join(map(str, values)))


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
