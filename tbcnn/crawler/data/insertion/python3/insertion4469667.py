def insert_sort(n:int, s:list):
    print(' '.join(map(str, s)))
    for i in range(1, len(s)):
        j = i - 1
        v = s[i]
        while (j >= 0 and s[j] > v):
            s[j + 1] = s[j]
            j -= 1
            s[j + 1] = v
        print(" ".join(map(str, s)))

insert_sort(int(input()),list(map(int,input().split(' '))))

