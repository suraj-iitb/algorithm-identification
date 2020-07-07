import sys

l = []
for i in sys.stdin:
    l.append(i.split())

def bubble_sort(data):
    count = 0
    for i in range(0,len(data)):
        for j in range(len(data)-1,i,-1):
            if data[j] < data[j-1]:
                count += 1
                temp = data[j]
                data[j] = data[j-1]
                data[j-1] = temp
    for i in range(0,len(data)):
        print(data[i],end='')
        print(" ",end='') if i < len(data)-1 else print()
    print(count)

for i in range(0,len(l[1])):
    l[1][i] = int(l[1][i])

bubble_sort(l[1])
