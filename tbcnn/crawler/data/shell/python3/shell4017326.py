class solve:
    def __init__(self, n):
        pass

    def insertionsort(self, A, n, g):
        for i in range(g, n):
            v = A[i]
            j = i - g
            while j >= 0 and A[j] > v:
                A[j + g] = A[j]
                j = j - g
                self.cnt += 1
            A[j + g] = v

    def shellsort(self, A, n):
        self.cnt = 0
        self.G = [1]
        f = 1
        while f * 3 + 1 <= n:
            f = f * 3 + 1
            self.G.append(f)
        self.G = list(reversed(self.G))
        self.m = len(self.G)
        for g in self.G:
            self.insertionsort(A, n, g)


n, *A = map(int, open(0).read().split())
solver = solve(n)
solver.shellsort(A, n)
print(solver.m)
print(' '.join(map(str, solver.G)))
print(solver.cnt)
print('\n'.join(map(str, A)))
