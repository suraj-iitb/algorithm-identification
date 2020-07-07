def show(lst):
    length = len(lst)
    for i in range(length-1):
        print(lst[i], end=" ")
    print(lst[-1])
        
    

n = int(input())
lst = list(map(int, input().split()))
def insertion_sort(lst, n):
    for i in range(n):
        v = lst[i]
        j = i - 1
        while j >= 0 and lst[j] > v:
            lst[j+1] = lst[j]
            j -= 1
        lst[j+1] = v
        show(lst)
insertion_sort(lst, n)
