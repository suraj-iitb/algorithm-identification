#1_A
def insertion_sort(a, n):
    for i in range(n-1):
        j = i
        i = i + 1
        v = a[i]
        while j>=0 and a[j]>v:
            a[j+1] = a[j]
            j -= 1
        a[j+1] = v
        
        pr = str(a[0])
        for i in range(n-1):
            i = i + 1
            pr += " " + str(a[i])
        print(pr)

n = int(input())
a = list(map(int, input().split()))

pr = str(a[0])
for i in range(n-1):
    i = i + 1
    pr += " " + str(a[i])
print(pr)

insertion_sort(a, n)
