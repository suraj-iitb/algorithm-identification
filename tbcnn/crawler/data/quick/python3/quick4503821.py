def partition(a, p, r):
    x = int(a[r].split()[1])
    i = p-1
    for j in range(p, r):
        if int(a[j].split()[1]) <= x:
          i = i+1
          a[i], a[j] = a[j], a[i]
    a[i+1], a[r] = a[r], a[i+1]
    return i+1

def quick_sort(a, p, r):
    if p < r:
        q = partition(a, p, r)
        quick_sort(a, p, q - 1)
        quick_sort(a, q + 1, r)

n = int(input())
cards = [input() for i in range(n)]
stable = sorted(cards, key=lambda x: int(x.split()[1]))
quick_sort(cards, 0, n - 1)

print("Stable" if stable == cards else "Not stable")

for card in cards:
    print(card)
