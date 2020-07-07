def bubbles(N):
    count = 0
    for i in range(len(N)):
        for j in range(len(N)-1, i, -1):
            if N[j] < N[j-1]:
                N[j], N[j-1] = N[j-1], N[j]
                count += 1
    c = 1
    for i in N:
        print(i, end='')
        if c < len(N):
            print(' ', end='')
            c += 1
    print('')
    return count

n = int(input())
numbers = list(map(int, input().split()))

print(bubbles(numbers))
