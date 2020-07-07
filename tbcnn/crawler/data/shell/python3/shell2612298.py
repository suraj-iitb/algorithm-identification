n = int(input())
cn= 1
an= [1]
i = 1

while cn < n / 4: 
    an.append(cn*3+1)
    cn=cn*3+1
an.sort(reverse=True)

def insertionSort(a,n,g):
    cnt=0
    for i in range(g,n):
        v = a[i]
        j = i - g
        while j>= 0 and a[j]>v:
            a[j + g]= a[j]
            j = j-g
            cnt+=1
        a[j + g]=v
    return cnt

def shellSort(a,n,an):
    cnt=0
    m = len(an)
    g = an
    for i in an:
        cnt += insertionSort(a,n,i)
    return cnt


x=[]
for i in range(n):
    x.append(int(input()))

print(len(an))
print(" ".join([str(i) for i in an]))
y= shellSort(x,n,an)
print(y)

for i in range(n):
    print(x[i])
