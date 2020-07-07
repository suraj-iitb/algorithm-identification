class inte:
	n = 0
	def __init__(self, n):
		self.n = n
	def chmax(self, n):
		self.n = n if self.n < n else self.n
	def chmin(self, n):
		self.n = n if self.n > n else self.n

N = int(input())
A = list(map(int, input().split()))

def sort(a):
	count = 0
	while True:
		for i in reversed(range(1, len(a))):
			if a[i] < a[i - 1]:
				a[i], a[i - 1] = a[i - 1], a[i]
				count += 1
				break
		else:
			return count

count = sort(A)
print(*A)
print(count)

