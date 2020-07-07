n = int(input())
a = list(map(int, input().split()))
cnt = 0

def selection_sort(a):
    global cnt
    for i in range(len(a)):
        min_idx = i
        for j in range(i + 1, len(a)):
            if a[j] < a[min_idx]:
                min_idx = j
                #cnt += 1
        if i != min_idx:
            a[i], a[min_idx] = a[min_idx], a[i]
            cnt += 1

selection_sort(a)
print(*a)
print(cnt)
