import math
import itertools

def main():
  n = int(input())
  A = list(map(int, input().split()))
  len_A = len(A)
  times = 0

  for i in range(len_A):
    for j in reversed(range(i+1, len_A)):
      if A[j] < A[j-1]:
        tmp = A[j]
        A[j] = A[j-1]
        A[j-1] = tmp
        times += 1

  print(*A)
  print(times)

if __name__ == '__main__':
  main()
