def CountingSort(A,B,num):

	k = max(A)
	C = [0 for _ in range(k+1)]
	#C[i]にiの出現回数を記録する
	for i in A:
		C[i] += 1

	#C[i]にi以下の数の出現数を記録する =>累積度数分布を出力
	for j in range(1,k+1):
		C[j] += C[j-1]
	for h in range(num-1,-1,-1):
		B[C[A[h]]-1] = A[h]
		C[A[h]] -= 1

if __name__ == '__main__':

	num = int(input())
	A = [int(i) for i in input().split()]

	B = [0 for _ in range(num+1)]
	CountingSort(A,B,num)

	B.pop()
	print(" ".join(map(str,B)))

