def countingsort(a):
    max_num = max(a)
    min_num = min(a)
    count = [0]*(max_num - min_num + 1)
    for ele in a:
        count[ele - min_num] += 1

    return [ele for ele,cnt in enumerate(count,start = min_num) for _ in range(cnt)]

        

n = int(input())
A = [int(s) for s in input().split()]
print(" ".join(map(str,countingsort(A))))
