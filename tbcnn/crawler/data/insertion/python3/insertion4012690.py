# coding: utf-8
# Your code here!

def insertionSort(A, N):
    for i in range(1, N):
            #print("sorting")
            v = A[i]
            j = i - 1
            while j >= 0 and A[j] > v:
                A[j + 1] = A[j]
                j -= 1
            A[j + 1] = v
            
            for k in range(N-1):
                print(str(A[k]), end = " ")
            print(A[N-1])

N = int(input())
A = list(map(int, input().split())) 
#for i in range(N - 1):
 #   A[i] = int(A[i])

for k in range(N-1):
     print(str(A[k]), end = " ")
print(A[N-1])

insertionSort(A, N)
