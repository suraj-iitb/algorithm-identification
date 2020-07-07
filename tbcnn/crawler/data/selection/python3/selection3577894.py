n = int(input())
a = list(map(int, input().split()))

count = 0
for i in range(n):
    mini = i
    for j in range(i,n):
        if a[j]<a[mini]:
            mini = j
    key = a[mini]
    a[mini] = a[i]
    a[i] = key
    if mini!=i:count += 1

string = ''
for s_val in a[:-1]:
    string += str(s_val) + ' '
string += str(a[-1])
print(string)
print(count)
