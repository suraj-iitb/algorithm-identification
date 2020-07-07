n = int(input())
original_list = list(map(int,input().split()))
maped_list = map(str, original_list)
print(' '.join(maped_list))
for i in range(1,n):
    v = original_list[i]
    j = i - 1
    while j >= 0 and original_list[j] > v:
        original_list[j+1] = original_list[j]
        j = j - 1
    original_list[j+1] = v
    maped_list = map(str,original_list)
    print(' '.join(maped_list))
