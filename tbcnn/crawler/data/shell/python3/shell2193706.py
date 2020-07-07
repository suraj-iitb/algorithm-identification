n = int(input())
A = list()
G = [1]
cnt = 0

for i in range(0, n):
    A.append(int(input()))


def insertion_sort(A, n, g):
    global cnt
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j -= g
            cnt += 1
        A[j+g] = v


# G[i] = 3*Gi-1 + 1
def shell_sort():
    for i in range(1, 101):
        h = 3 * G[0] + 1
        if h > n:  # h???n?¶???????????????§?????????4n+3*2n-1+1
            break
        else:
            G.insert(0, h)
    for g in G:
        insertion_sort(A, n, g)

shell_sort()
print(len(G))
print(" ".join(str(x) for x in G))
print(cnt)
print("\n".join(str(x) for x in A))
