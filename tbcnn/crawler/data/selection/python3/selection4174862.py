# min(A): リストAの最小値を返す
# A.index(min(A)): リストAの最小値のindexを返す
# リストのスライス A[start:stop]でstart <= i < stopの値を返す．stopの値は含まれない
def SelectionSort(N, A):
   count = 0 # 交換回数カウント変数
   for i in range(0, N-1):
      minj = i
      for j in range(i+1, N): # 未ソート部分から最後まで
         if A[j] < A[minj]:
            minj = j # 最小値のindexを変更
      # print('Before: ', *A)
      if A[minj] < A[i]:
         A[i], A[minj] = A[minj], A[i]
         count+=1
      # print(' After: ', *A)
   return A, count

N = int(input())
A = list(map(int, input().split())) # 「1 2 3…」のような配列入力
ans, count = SelectionSort(N, A)
print(*ans)
print(count)
