array_to_str = lambda A: ' '.join([str(a) for a in A])
input_number = lambda: int(input())
input_num_array = lambda: [int(a) for a in input().split()]

def bubble_sort(A, N):
  flag = 1
  exchange_num = 0
  while flag:
    flag = 0
    for j in range(N)[:0:-1]:
      if A[j] < A[j-1]:
        exchange_num += 1
        A[j],A[j-1] = A[j-1], A[j]
        flag = 1
  print(array_to_str(A))
  print(exchange_num)
  
N = input_number()
A = input_num_array()
bubble_sort(A, N)
