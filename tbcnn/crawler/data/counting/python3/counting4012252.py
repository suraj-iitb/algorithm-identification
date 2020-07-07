def count_sort(numlist, n):
    C = [0 for i in range(n + 1)]
    B = [0 for i in range(len(numlist))]
    # store times that num has appear
    for num in numlist:
        C[num] += 1
    # cal index
    for i in range(1, n + 1):
        C[i] += C[i - 1]
    for n in range(len(numlist), 0, -1):
        C[numlist[n - 1]] -= 1
        B[C[numlist[n - 1]]] = numlist[n - 1]

    return B

if __name__ == '__main__':
    n = int(input())
    numlist = [int(num) for num in input().split(' ')]
    numlist = count_sort(numlist, max(numlist))
    print(str(numlist).replace(',', '').replace('[', '').replace(']', ''))
