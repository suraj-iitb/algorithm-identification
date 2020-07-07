N = int(input())
A = list(map(int, input().split()))

L = A[:]
sorted_l = []
un_sorted_l = L[:]
counter = 0
while un_sorted_l:
    n = len(un_sorted_l)
    for i in reversed(range(1, n)):
        if un_sorted_l[i-1] <= un_sorted_l[i]:
            continue
        else:
            counter += 1
            un_sorted_l[i-1], un_sorted_l[i] = un_sorted_l[i], un_sorted_l[i-1]
    sorted_l.append(un_sorted_l[0])
    un_sorted_l = un_sorted_l[1:]


print(' '.join(map(str, sorted_l)))
print(counter)    

