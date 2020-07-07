def counting_sort(inArr, outArr, k):
    cntArr = [0] * (k + 1)
    for i in range(len(inArr)):
        cntArr[inArr[i]] += 1

    cntArr[0] -= 1
    for i in range(1, k+1):
        cntArr[i] += cntArr[i - 1]

    for i in range(len(inArr) - 1, -1, -1):
        outArr[cntArr[inArr[i]]] = inArr[i]
        cntArr[inArr[i]] -= 1

n = int(input())
num_list = [int(s) for s in input().split()]

sorted_list = [0] * n
counting_sort(num_list, sorted_list, 10000)

print(*sorted_list)
