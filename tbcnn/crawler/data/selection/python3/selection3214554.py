def main():
    n = int(input())
    array = [int(x) for x in input().split()]

    cnt = 0
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if array[min_idx] > array[j]:
                min_idx = j
        if min_idx != i:
            tmp = array[i]
            array[i] = array[min_idx]
            array[min_idx] = tmp
            cnt += 1

    print(" ".join(map(str, array)))
    print(cnt)


main()
