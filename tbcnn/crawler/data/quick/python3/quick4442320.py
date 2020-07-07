def partition(A, p, r):
    x = A[r][1]
    i = p-1
    for j in range(p, r):
        if A[j][1] <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[r] = A[r], A[i+1]
    return i+1

def quick_sort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quick_sort(A, p, q-1)
        quick_sort(A, q+1, r)

n = int(input())
card = []
tmpdic = {}
for i in range(n):
    suit, num = input().split()
    num = int(num)
    card.append((suit, num))
    if num in tmpdic:
        tmpdic[num] += suit
    else:
        tmpdic[num] = suit

order = ""
for i in sorted(tmpdic.keys()):
    order += tmpdic[i]

quick_sort(card, 0, n-1)

for i in range(n):
    if order[i] != card[i][0]:
        print("Not stable")
        break
    if i == n-1:
        print("Stable")

for suit, num in card:
    print(f"{suit} {num}")
