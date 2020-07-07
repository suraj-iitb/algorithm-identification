n = int(input())
arr = []
for i in range(n):
  arr.append(int(input()))

m = [1]
for i in range(1, 100):
  m.append(3 * m[-1] + 1)
m = list(reversed([x for x in m if x <= n]))

cnt = 0
def insertionSort(arr, n, g):
  for i in range(g, n):
    v = arr[i]
    j = i - g
    while j >= 0 and arr[j] > v:
      arr[j + g] = arr[j]
      j = j - g
      global cnt
      cnt += 1
    arr[j+g] = v

def shellSort(arr, n):
  for i in range(len(m)):
    insertionSort(arr, n, m[i])

shellSort(arr, n)

print(len(m))
print(' '.join([str(x) for x in m]))
print(cnt)
for i in range(len(arr)):
  print (arr[i])
