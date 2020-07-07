N = int(input())
A = list(map(int, input().split()))

selection_sort = A[:]

counter = 0
for i in range(len(selection_sort)):
    v = selection_sort[i]
    min_v = v
    min_i = i
    for j in range(i, len(selection_sort)):
        if min_v > selection_sort[j]:
            min_v = selection_sort[j]
            min_i = j
    if v != min_v:
        counter += 1
        selection_sort[i], selection_sort[min_i] = selection_sort[min_i], selection_sort[i]
        
print(' '.join(map(str, selection_sort)))
print(counter)
        
    
