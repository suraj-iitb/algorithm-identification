import math
import itertools

def main():
  n = int(input())
  A = list(map(int, input().split()))
  len_A = len(A)
  times = 0

  for i in range(len_A):
    min = i
    for j in range(i+1, len_A):
      if A[j] < A[min]:
        min = j
    
    if min != i:
      tmp = A[min]
      A[min] = A[i]
      A[i] = tmp
      times += 1

  print(*A)
  print(times)

if __name__ == '__main__':
  main()
