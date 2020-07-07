def insertion_sort(a, n, g):
    global count
    for i in range(g, n):
        v = a[i]
        j = i - g
        
        while j >= 0 and a[j] > v:
            a[j+g] = a[j]
            j = j - g
            count += 1
        a[j+g] = v

def shell_sort(a, n):

    g = []
    i = 1
    while i <= len(a):
      g.append(i)
      i = i*3 +1
    g.reverse()
    print(len(g))
    print(" ".join(map(str, g)))
    
    for i in g:
        insertion_sort(a=a, n=n, g=i)

        
n = int(input())
a = []
for i in range(n):
  a.append(int(input()))

count = 0
shell_sort(a=a, n=n)
print(count)
for i in range(n):
  print(a[i])




    
        
