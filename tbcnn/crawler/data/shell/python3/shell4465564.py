def insertion(mi):
    cnt = 0
    for i in range(mi, n):
        v = A[i]
        j = i - mi
        while j >= 0 and A[j] > v:
            A[j+mi] = A[j]
            j -= mi
            cnt += 1
        A[j+mi] = v
    return cnt


def shell():
    g = list()
    h = 1

    if n == 1:
        g.append(h)
    else:
        while h < len(A):
            g.append(h)
            h = 3 * h + 1

    return g


n = int(input())
A = list()
m = list()
count = 0

for k in range(n):
    A.append(int(input()))

m = shell()

print(len(m))

m_list = [str(m[k]) for k in reversed(range(len(m)))]
print(' '.join(m_list))

for k in reversed(m):
    count += insertion(k)

print(count)

for k in range(len(A)):
    print(A[k])

