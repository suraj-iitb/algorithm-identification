def main():
    n = int(input())
    array = [int(x) for x in input().split()]

    cnt = 0
    while True:
        flag = False
        for i in range(1, n)[::-1]:
            if array[i-1] > array[i]:
                tmp = array[i]
                array[i] = array[i-1]
                array[i-1] = tmp
                flag = True
                cnt += 1
        if not flag:
            break
    print(" ".join(map(str, array)))
    print(cnt)


main()
