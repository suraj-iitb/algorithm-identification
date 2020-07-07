def bubble_sort(n, a):
  flag = True
  count = 0
  while flag:
    flag = False
    for i in range(n - 1):
      if a[i] > a[i + 1]:
        a[i], a[i + 1] = a[i + 1], a[i]
        flag = True
        count += 1
  print(*a)
  print(count)

bubble_sort(int(input()), [int(i) for i in input().split()])

