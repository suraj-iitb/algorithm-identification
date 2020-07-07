def merge(L,R):
  T=[]
  for l in L[::-1]:
    while R and R[-1] > l:
      T += [R.pop()]
    T += [l]
  return R+T[::-1]

def mergesort(A):
  l = len(A)
  global c
  c += l
  s = l // 2
  return merge(mergesort(A[:s]),mergesort(A[s:])) if l > 1 else A

def solver():
  print(*mergesort(list(map(int,input().split()))))
  print(c)

c = -int(input())


solver()


