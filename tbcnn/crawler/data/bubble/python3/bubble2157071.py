def bubble_sort(target):
    global cnt
    flag = True
    while flag:
        flag = False
        for i in range(len(target)-1, 0, -1):
            if target[i] < target[i-1]:
                target[i-1], target[i] = target[i], target[i-1]
                flag = True
                cnt += 1
    return target

N = int(input())
A = [int(s) for s in input().split()]
cnt = 0
print(' '.join(str(s) for s in bubble_sort(A)))
print(cnt)
