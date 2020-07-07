

def bsort(array):
    i = 0
    counter = 0
    while i < len(array)-1:
        for c in range(len(array)-1,i,-1):
            if array[c]<array[c-1]:
                a = array[c-1]
                array[c-1] = array[c]
                array[c] = a
                counter += 1

        i = i+1
    resul = ' '.join([str(i) for i in array])
    print(resul)
    print(counter)

n = int(input())

inputarr = input().split()
intarr = [int(i) for i in inputarr]

bsort(intarr)
