def insertSort(n, a):
  for i in range(n):
    v = a[i]
    j = i - 1
    while 0 <= j and v < a[j]:
      a[j + 1] = a[j]
      j -= 1
    a[j + 1] = v
    print(*a)

insertSort(int(input()), [int(i) for i in input().split()])

