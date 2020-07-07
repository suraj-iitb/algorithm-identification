n = int(input())
v = list(map(int, input().split()))

res = v.copy()

for i in range(n):
    if i == 0:
        pass
    else:
        for j in range(i):
            if res[j] > v[i]:
                res.pop(i)
                res.insert(j, v[i])
                break

    print(" ".join([str(x) for x in res]))
