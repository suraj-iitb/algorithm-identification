_ = input()
a = list(map(int, input().split()))

flag = 1
counter = 0

while flag:
    flag = 0

    for j in range(len(a)-1, 0, -1):
        if a[j] < a[j-1]:
            a[j], a[j-1] = a[j-1], a[j]
            flag = 1
            counter += 1
 
print(" ".join(map(str, a)))
print(counter)
