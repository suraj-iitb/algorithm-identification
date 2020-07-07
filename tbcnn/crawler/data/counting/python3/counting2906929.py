def CountingSort(n, input_line, max_num):
    max_num += 1
    count_list = [0 for i in range(max_num)]
    output_line = [0 for i in range(n)]
    for i in range(n):
        count_list[input_line[i]] += 1
    for i in range(1,max_num):
        count_list[i] = count_list[i] + count_list[i-1]
    for i in range(n-1,-1, -1):
        output_line[count_list[input_line[i]]-1] = str(input_line[i])
        count_list[input_line[i]] -= 1
    return output_line

n = int(input())
input_line = [int(i) for i in input().split()]
max_num = max(input_line)
output_line = CountingSort(n, input_line, max_num)
print(' '.join(output_line))
