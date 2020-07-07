def selections(N):
    count = 0
    for i in range(len(N)):
        mini = i
        for j in range(i+1, len(N)):
            if N[mini] > N[j]:
                mini = j
        if i != mini:
            N[mini], N[i] = N[i], N[mini]
            count += 1
    c = 1
    for i in N:
        print(i, end='')
        if c < len(N):
            print(' ', end='')
            c += 1
    print('')
    print(count)
     
n = int(input())
numbers = list(map(int, input().split()))
 
selections(numbers)
