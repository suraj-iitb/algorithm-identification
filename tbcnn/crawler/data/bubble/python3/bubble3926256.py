n = int(input())
a = list(map(int, input().split()))
cnt = 0

def bubble_sort(a):
    global cnt
    for i in range(len(a)):
        l = 0
        r = 1

        while r < len(a):
            if a[l] > a[r]:
                a[l], a[r] = a[r], a[l]
                cnt += 1
            l += 1
            r += 1


    # for i in range(len(a)):
    #     for j in range(i + 1, len(a)):
    #         if a[i] > a[j]:
    #             a[i], a[j] = a[j], a[i]

bubble_sort(a)
print(*a)
print(cnt)

