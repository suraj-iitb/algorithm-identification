def quickSort(A, p, r):
  if p < r:
    q = partition(A, p, r)
    quickSort(A, p, q-1)
    quickSort(A, q+1, r)


def partition(A, p, r):
  x = A[r]
  i = p -1

  for j in range(p, r):
    if A[j][1] <= x[1]:
      i += 1
      A[i], A[j] = A[j], A[i]
  A[i+1], A[r] = A[r], A[i+1]
  return i+1


deck = []
n = int(input())
for index in range(n):
  mark, number = input().split()
  card = [mark, int(number), index]

  deck.append(card)

quickSort(deck, 0, n-1)

ans = 'Stable'
for i in range(1, n):
  if deck[i-1][1] == deck[i][1]:
    if deck[i-1][2] > deck[i][2]:
      ans = 'Not stable'
      break
print (ans)
for v in deck:
  print ('{mark} {number}'.format(mark=v[0], number=v[1]))
