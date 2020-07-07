# リストの宣言
A = []

# 入力の最初の行に、数列の長さを表す整数 N が与えられます。
# 2 行目に、N 個の整数が空白区切りで与えられます。
NUM =int(input())
A = input().split()

print(" ".join(map(str,A)))

NUMLIST = range (1, NUM)

# for i = 1 to A.length-1
for i in NUMLIST:
#    key = A[i]
  key = A[i]
  j = i - 1
  while j >= 0 and int(A[j]) > int(key):
    A[j+1] = A[j]
    j-=1
  A[j+1] = key
  print(" ".join(map(str, A)))


