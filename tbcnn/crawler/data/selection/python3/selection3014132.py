n = int(input())
s = [int(x) for x in input().split()]

swap_cnt = 0

for i in range(n) :
    cmin = i
    for j in range(i + 1, n) :
        if s[j] < s[cmin] :
            cmin = j
            
    if i != cmin :
        s[i], s[cmin] = s[cmin], s[i]
        swap_cnt += 1
                
print(" ".join(map(str, s)))
print(swap_cnt)

