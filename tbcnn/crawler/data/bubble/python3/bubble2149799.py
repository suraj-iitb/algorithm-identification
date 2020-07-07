def bubble_sort(r, n):
    flag = True  # ??£??\????´?????????¨????????°
    count = 0
    while flag:
        flag = False
        for i in range(n-1, 0, -1):
            if r[i-1] > r[i]:
                r[i-1],r[i] = r[i],r[i-1]
                count += 1
                flag = True

    print(*r)
    print(count)

N = int(input())
A = list(map(int, input().split()))
bubble_sort(A,N)
