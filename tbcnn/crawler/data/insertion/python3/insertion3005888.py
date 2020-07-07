N = int(input())
a = [int(x) for x in input().split()]

for i in range(0, len(a)) :
    repl = i
    cur_num = a[i]
    
    # fetch idx to replace
    for j in range(i, -1, -1) :
        if a[j] >= a[i] :
            repl = j
    
    # shift
    for k in range(i, repl - 1, -1) :
        a[k] = a[k - 1]
    
    a[repl] = cur_num
    
    print(" ".join(map(str, a)))

