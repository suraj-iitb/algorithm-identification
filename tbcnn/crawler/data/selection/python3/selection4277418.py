def select_sort(n, a):
  count = 0
  for i in range(n):
    minj = i
    for j in range(i, n):
      if a[j] < a[minj]:
        minj = j
    if i != minj:
      a[i], a[minj] = a[minj], a[i]
      count += 1
  print(*a)
  print(count)

select_sort(int(input()), [int(i) for i in input().split()])

