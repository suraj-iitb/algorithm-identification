n=int(input())
a=list(map(int, input().split()))

def selection(a:list, n:int) -> None:
    if not isinstance(a, list):
        return None

    cnt=0
    for i in range(n):
        minj=i
        for j in range(i, n):
            if a[j] < a[minj]:
                minj=j
        a[i], a[minj] = a[minj], a[i]

        if i != minj: cnt+=1

    print(" ".join(map(str, a)))
    print(cnt)

selection(a, n)
