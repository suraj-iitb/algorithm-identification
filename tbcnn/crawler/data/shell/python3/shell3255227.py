def insertion_sort(num_list,gap):
    global cnt
    for i in range(gap,len(num_list)):
        swap_num = num_list[i]
        j = i-gap
        while j >= 0 and num_list[j] > swap_num:
            num_list[j+gap] = num_list[j]
            j -= gap
            cnt += 1
        num_list[j+gap] = swap_num

def shell_sort(num_list):
    global cnt 
    cnt = 0
    m = 1
    m_list = []
    while len(num_list) >= m:
        m_list.append(m)
        m = 3*m+1
    m_list.reverse()
    print(len(m_list))
    print(' '.join([str(i) for i in m_list]))

    for i in range(len(m_list)):
        insertion_sort(num_list,m_list[i])
    print(cnt)

n = int(input())
num_list = [int(input()) for _ in range(n)]
shell_sort(num_list)
for num in num_list:
    print(num)
