# リストの宣言
A = []

# 入力の最初の行に、数列の長さを表す整数 N が与えられます。
# 2 行目に、N 個の整数が空白区切りで与えられます。
LENGTH =int(input())
A = input().split()

# 変数
N = 0
M = LENGTH - 1
CHANGE = 0

# BubbleSort(A)
#  for i = 0 to A.length-1
while N <= LENGTH -1 :
    M = LENGTH - 1
#    print ('N=',N)
#      for j = A.length-1 downto i+1
    while M >= N + 1:
#       print  ('-M=',M)
#          if A[j] < A[j-1]
        if int(A[M]) < int(A[M-1]) :
            tmp = A[M-1]
            A[M-1] = A[M]
            A[M] = tmp
            CHANGE += 1
        M -= 1
    N += 1

print(" ".join(map(str,A)))
print (CHANGE)
