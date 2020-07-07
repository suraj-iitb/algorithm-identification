class Shellsort():
    def __init__(self, x, n):
        self.x = x
        self.n = n
    
    def sorting(self):
        self.cnt = 0
        self.G = [1]
        i = 0
        while 1:
            z = self.G[i] * 3 + 1
            if z > self.n or len(self.G) == 20:
                break
            self.G.append(z)
            i += 1
        
        self.G.sort(reverse = True)
        self.m = len(self.G)
        for i in range(self.m):
            self.insertation(self.G[i])
        return self
    
    def insertation(self, g):
        for i in range(g, self.n):
            v = self.x[i]
            j = i - g
            while j >= 0 and self.x[j] > v:
                self.x[j + g] = x[j]
                j = j - g
                self.cnt += 1
            self.x[j + g] = v

n = int(input())
x = [0] * n
for i in range(n):
    x[i] = int(input())

a = Shellsort(x, n).sorting()

print(a.m)
L = [str(i) for i in a.G]
print(' '.join(L))
print(a.cnt)
for i in a.x:
    print(i)
