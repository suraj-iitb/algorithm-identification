def sort(l):
    
    for i in range(len(l)) :
        key = l[i]
        j = i-1
        while j>=0 and l[j]>key:
            l[j+1] = l[j]
            j -= 1
            
        l[j+1] = key
        print(" ".join(map(str,l)))

n = int(input())
line = list(map(int,input().split(" ")))

sort(line)
