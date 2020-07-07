def inserts(N):
    k = 1
    for n in N:
        print(n, end='')
        if k < len(N):
            print(' ', end='')
        k += 1

    print('')
    for i in range(1,len(N)):
        # ?????????????´??????????????????£????????¨?????????
        v = N[i]
        j = i - 1
        while j >= 0 and N[j] > v:
            N[j + 1] = N[j]
            j -= 1
        N[j + 1] = v
        k = 1
        for n in N:
            print(n, end='')
            if k < len(N):
                print(' ', end='')
            k += 1
        print('')


n = int(input())
numbers = list(map(int, input().split()))

inserts(numbers)
