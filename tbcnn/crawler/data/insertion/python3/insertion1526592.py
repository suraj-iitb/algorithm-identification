input()
xs = list(map(int, input().split()))

def insertion_sort(xs):
  for i in range(1, len(xs)):
    v = xs[i]
    j = i - 1
    while j >= 0 and xs[j] > v:
      xs[j + 1] = xs[j]
      j -= 1
    xs[j + 1] = v
    print(*xs)

print(*xs)
insertion_sort(xs)
