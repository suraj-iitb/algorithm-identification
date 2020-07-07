cnt = 0
def SelectionSort(L):
    global cnt
    for i in range(len(L)):
        minj = i
        for j in range(i+1, len(L)):
            if L[minj] > L[j]:
                minj = j
        if minj != i:
            cnt += 1
            L[i], L[minj] = L[minj], L[i]

n = int(input())
NUM_LIST = list(map(int, input().split()))

SelectionSort(NUM_LIST)
STR = list(map(str, NUM_LIST))
print(" ".join(STR))
print(cnt)
