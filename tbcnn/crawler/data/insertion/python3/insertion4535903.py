def show_nums(nums):
    for i in range(len(nums)):
        if i != len(nums) - 1:
            print(A[i], end = ' ')
        else:
            print(A[i])
            

N = int(input())
input_list = input().split(' ')
A = []
for i in input_list:
    A.append(int(i))
if len(input_list) != N:
    raise ValueError('N個の整数を入力してください。')

for i in range(N):
    v = A[i]
    j = i - 1
    while j >= 0 and v < A[j]:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = v
    show_nums(A)

