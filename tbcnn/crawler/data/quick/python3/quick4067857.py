def partition(A,p,r):
    x = A[r][1]
    i = p - 1
    for j in range(p,r):
      if A[j][1] <= x:
          i += 1
          A[i],A[j] = A[j], A[i]
    A[i+1],A[r] = A[r],A[i+1]
    return i+1

def quicksort(A,p,r):
    if p < r:
        q = partition(A,p,r)
        quicksort(A,p,q-1)
        quicksort(A,q+1,r)

class checkstable:
    def __init__(self):
        self.d = {}
    def storecards(self,A):
        for i in range(len(A)):
            if A[i][1] in self.d:
                self.d[A[i][1]].append(A[i][0])
            else:
                 self.d[A[i][1]] = [(A[i][0])]

    def isstable(self,A):
        for i in range(len(A)):
            if self.d[A[i][1]].pop(0) != A[i][0]:
                      return "Not stable"
        return "Stable"

n = int(input())
A = []
for _ in range(n):
   mark,num = input().split()
   num = int(num)
   A.append([mark,num])
quick = checkstable()
quick.storecards(A)

quicksort(A,0,n - 1)
stable = quick.isstable(A)
print(stable)
for i in range(n):
   print(*A[i])

