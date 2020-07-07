N = int(input())
A = list(map(int,input().split()))
flag = 1
count = 0

while flag:
    flag = 0
    for i in range(N-1,0,-1):
        if A[i] < A[i-1]:
          tmp = A[i]
          A[i] = A[i-1]
          A[i-1] = tmp
          flag = 1
          count += 1
print(' '.join([str(a) for a in A])) 
print(count)
