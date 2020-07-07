n = int(input())
arr = list(map(int, input().split()))

frag = True
ex = 0

while frag:
    frag = False
    for j in range(n-1, 0, -1):
        if arr[j-1] > arr[j]:
            arr[j-1], arr[j] = arr[j], arr[j-1]
            frag = True
            ex += 1



def print_space(li):
    for i in range(len(li)-1):
        print(li[i], end=' ')
    else:
        print(li[-1])

        
print_space(arr)
print(ex)

