# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A&lang=jp
sample_input = list(range(3))
sample_input[0] = '''5
5 3 2 4 1'''
sample_input[1] = '''6
5 2 4 6 1 3'''
sample_input[2] = '''1
100'''
give_sample_input = None
if give_sample_input is not None:
    sample_input_list = sample_input[give_sample_input].split('\n')
    def input():
        return sample_input_list.pop(0)
        
# main part
def swap_list_item(lst, i, j):
    tmp = lst[i]
    lst[i] = lst[j]
    lst[j] = tmp

num_of_data = int(input())
list_of_data = list(map(int, input().split()))

swap_count = 0
flag = True
while flag:
    flag = False
    n = num_of_data - 1
    while n >= 1:
        if list_of_data[n] < list_of_data[n-1]:
            swap_list_item(list_of_data, n, n-1)
            flag = True
            swap_count += 1
        n -= 1

result = ''
for number in list_of_data:
    result += str(number) + ' '
print(result.strip())
print(swap_count)
