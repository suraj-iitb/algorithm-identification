def BubbleSort(N ,A): # バブルソート
   count = 0
   for i in range(N): # 未ソート部分列は一つずつ減っていく
      for j in range(N-1, i, -1): # 一番後ろ(配列的にはN-1番目)から未ソート部分列の先頭(i+1)まで
         if A[j] < A[j-1]: # 後ろより前の方が大きかったら交換
            A[j], A[j-1] = A[j-1], A[j]
            count+=1 # 交換回数をカウント
   return A, count

N = int(input())
A = list(map(int, input().split())) # 「1 2 3…」のような配列入力
ans, count = BubbleSort(N, A)
print(*ans)
print(count)
