count = 0
m = 0
g_string = ''

def insertionSort(numbers, n, g):
    global count    
    for i in range(g, n):
        v = numbers[i]
        j = i - g
        while j >= 0 and numbers[j] > v:
            numbers[j + g] = numbers[j]
            count += 1
            j = j - g
        numbers[j + g] = v

def shellSort(numbers, n):
    global count
    global m
    global g_string
    count = 0
    m = 1
    gs = [1]
    i = 1
    while (i * 3 + 1) <= n:
        gs.append(i * 3 + 1)
        m += 1
        i = i * 3 + 1
    for i in range(m - 1, -1, -1):
        g_string += str(gs[i])
        g_string += " "
        insertionSort(numbers, n, gs[i])

n = int(input())
nums = []
for i in range(n):
    nums.append(int(input()))
shellSort(nums, n)
print(m)
print(g_string.rstrip())
print(count)
for i in range(n):
    print(nums[i])
