
def merge(s, left, mid, right):
    global count
    n1 = mid - left
    n2 = right - mid
    L = s[left:mid] + [1000000001]
    R = s[mid:right] + [1000000001]

    i = 0
    j = 0
    for k in range(left,right):
        count += 1
        if L[i] <= R[j]:
            s[k] = L[i]
            i += 1
        else:
            s[k] = R[j]
            j += 1

def mergesort(s, left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        mergesort(s, left, mid)
        mergesort(s, mid, right)
        merge(s, left, mid, right)

n = int(input())
count = 0
s = list(map(int, input().split()))
mergesort(s, 0, n)

for i in range(len(s)-1):
      print(s[i], end = " ")
print(s[n-1])
print(count)

