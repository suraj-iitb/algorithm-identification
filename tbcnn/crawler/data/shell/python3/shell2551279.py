

G = [120001,60001,30001,15001,3001,901,601,301,91,58,31,7,4,1]

def insertion_sort(array,g):
    for i in range(g,len(array)-1):
        v = array[i]
        j = i-g
        while j>=0 and array[j] > v:
            array[j+g] = array[j]
            j = j-g
            array[-1] += 1
        array[j+g] = v

def shell_sort(array,G):
    for i in G:
        insertion_sort(array,i)


n = int(input())
arr = [int(input()) for i in range(n)] + [0]
Gn = [i for i in G if i <= n]


shell_sort(arr,Gn)
print(len(Gn))
print(' '.join([str(i) for i in Gn]))
print(arr[-1])
[print(i) for i in arr[:-1]]
