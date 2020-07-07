def countingSort(a,n):
    count = [0]*(max(a)+1)
    for k in a:
      count[k] += 1
    for i in range(len(count)-1):
      count[i+1] += count[i]
    
    sorted_a = [0]*n

    for k in a[::-1]:
        sorted_a[count[k]-1] = k
        count[k] -= 1
    return sorted_a

n = int(input())
a = list(map(int,input().split()))
print(*countingSort(a,n))
