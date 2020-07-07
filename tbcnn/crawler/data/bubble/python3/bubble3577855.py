n = int(input())
a = list(map(int, input().split()))

count = 0
for i in range(n):
    for j in range(n-1,0,-1):
        if a[j]<a[j-1]:
            key = a[j]
            a[j] = a[j-1]
            a[j-1] = key
            count += 1

string = ''
for s_val in a[:-1]:
    string += str(s_val) + ' '
string += str(a[-1])
print(string)
print(count)
