cnt = 0

def insert_sort(g):

    global cnt

    i = g

    for _ in range(n):
        
        v = nums[i]

        j = i - g

        while j >= 0 and nums[j] > v:

            nums[j + g] = nums[j]
            
            j -= g

            cnt += 1
        
        nums[j + g] = v

        i += 1

        if i >= n:

            break


def shell_sort():

    i = 0

    for _ in range(m):

        insert_sort(g[i])

        i += 1

n = int(input())

nums = []

for _ in range(n):

    nums.append(int(input()))

g = []

g_val = n

for _ in range(n):

    g_val = g_val // 2

    g.append(g_val)

    if g_val == 1:

        break

m = len(g)

shell_sort()

print(m)

g_cnt = 0

s = ''

for _ in range(m):

    s += str(g[g_cnt]) + ' '

    g_cnt += 1

print(s.rstrip())

print(cnt)

nums_cnt = 0

for _ in range(n):

    print(nums[nums_cnt])

    nums_cnt += 1

