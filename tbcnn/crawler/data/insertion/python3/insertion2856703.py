import sys

n = int(input())

line_number = [int(i) for i in sys.stdin.readline().split()]

print(' '.join([str(s) for s in line_number]))

for i in range(1, n):
    v = line_number[i]
    j = i-1
    while (j >= 0) and (line_number[j] > v):
        line_number[j+1] = line_number[j]
        j = j-1
    line_number[j+1] = v
    print(' '.join([str(s) for s in line_number]))

