# SelectionSort(A)
#1 for i = 0 to A.length-1
#2     mini = i
#3     for j = i to A.length-1
#4         if A[j] < A[mini]
#5             mini = j
#6     swap A[i] and A[mini]

# リストの宣言
A = []

# 入力の最初の行に、数列の長さを表す整数 N が与えられます。
# 2 行目に、N 個の整数が空白区切りで与えられます。
LENGTH =int(input())
A = input().split()

# 変数
i = 0
CHANGE_COUNT = 0

while i <= LENGTH -1:
    j = i + 1
    mini = i
    while j <= LENGTH -1:
        if int(A[j]) < int(A[mini]) :
            mini = j
        j += 1
    if mini != i:
        tmp = A[i]
        A[i] = A[mini]
        A[mini] = tmp
        CHANGE_COUNT += 1
    i += 1

print(" ".join(map(str,A)))
print (CHANGE_COUNT)
