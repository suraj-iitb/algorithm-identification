def insertionsort(x):
    x = list(map(int, x))
    for i in range(len(x)):
        for k in range(i, 0, -1):
            if x[k-1] > x[k]:
                x[k-1], x[k] = x[k], x[k-1]
        print(" ".join(map(str, x)))


if __name__ == "__main__":
    input()
    insertionsort(input().split(" "))
