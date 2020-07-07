def countingsort(arr,maximum):
    m = maximum + 100
    count = [0] * (m)
    for a in arr:
        count[a] += 1
    i = 0
    for a in range(m):
        for c in range(count[a]):
            arr[i] = a
            i += 1
    return arr

if __name__ == '__main__':
    N = int(input())
    l = list(map(int, input().split()))

    a = 0
    li = countingsort(l,N)
    for a in range(N-1):
        print(li[a], end=" ")
    print(li[N-1])

