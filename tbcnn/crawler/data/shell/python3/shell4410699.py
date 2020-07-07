# shell sort

def insertion_sort(a, n, g, cnt):
    for i in range(g, n):
        v = a[i]
        j = i - g
        while j>=0 and a[j]>v:
            a[j+g] = a[j]
            j = j - g
            cnt += 1
        a[j+g] = v

    return cnt


def shell_sort(a, n, G, cnt):
    for i in range(m):
        cnt = insertion_sort(a, n, G[i], cnt)
    return cnt


# input
N = int(input())
nums = [0]*N
for i in range(N):
    nums[i] = int(input())

# initialization
G = [1]
h = 1
while h<N:
    h = 3*h + 1
while h>1:
    h = (h - 1) // 3
    G.append(h)
G = sorted(list(set(G)), reverse=True)
m = len(G)
cnt = 0

# sorting
cnt = shell_sort(nums, N, G, cnt)

# output
print(m)
print(" ".join(map(str, G)))
print(cnt)
for i in range(N):
    print(nums[i])

