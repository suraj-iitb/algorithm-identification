# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_B&lang=jp
sample_input = list(range(3))
sample_input[0] = '''6
5 6 4 2 1 3'''
sample_input[1] = '''6
5 2 4 6 1 3'''
sample_input[2] = ''''''
give_sample_input = None
if give_sample_input is not None:
    sample_input_list = sample_input[give_sample_input].split('\n')
    def input():
        return sample_input_list.pop(0)
        
# main
def swap_list_item(lst, i, j):
    tmp = lst[i]
    lst[i] = lst[j]
    lst[j] = tmp

num_of_data = int(input())
data_list = list(map(int, input().split()))
swap_count = 0
for i in range(num_of_data):
    minj = i
    for j in range(i, num_of_data):
        if data_list[minj] > data_list[j]:
            minj = j
    if not minj == i:
        swap_list_item(data_list, i, minj)
        swap_count += 1

result = ''
for number in data_list:
    result += str(number) + ' '
print(result.strip())
print(swap_count)
