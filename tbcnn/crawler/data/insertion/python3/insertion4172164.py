# insertionSort(A, N) // N個の要素を含む0-オリジンの配列A
def InsertionSort(A, N):
   for i in range(N):
      v = A[i]
      j = i - 1
      while(j >= 0 and A[j] > v):
         A[j+1] = A[j]
         j-=1
      A[j+1] = v
      print(*A)

N = int(input())
A = list(map(int, input().split())) # 「1 2 3…」のような配列入力
# print(*A) # リストの出力を数字とスペースのみにしてくれる
InsertionSort(A, N)
