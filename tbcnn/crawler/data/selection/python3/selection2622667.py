def main() :
    n = int(input())
    nums = [int(i) for i in input().split()]
    exchange_count = 0


    for i in range(n) :
        minj = i
        for j in range(i, n) :
            if nums[j] < nums[minj] :
                minj = j
        if minj != i :
            exchange_count += 1
        nums[i], nums[minj] = nums[minj], nums[i]

    print(" ".join(map(str, nums)))
    print(exchange_count)

if __name__ == '__main__' :
    main()
