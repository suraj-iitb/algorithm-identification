# ALDS1_2_D: Shell Sort

#N = 5
#A = [5, 1, 4, 3, 2]

#N = 3
#A = [3, 2, 1]

A = []
N = int(input())
for i in range(N):
    A.append(int(input()))

def insertionSort(A, N, g, cnt):
    #print(" ".join(map(str, A)))
    for i in range(g, N):
        v = A[i]
        j = i - g
        while j >= 0 and A[j] > v:
            A[j+g] = A[j]
            j = j - g
            cnt += 1
        A[j+g] = v
        #print(" ".join(map(str, A)))
    return cnt
    
def shellSort(A, N):
    cnt = 0
    #m = 2
    #listG = [4, 1] 
    h = 1
    listG = []
    while h <= N:
        listG.append(h)
        h = 3*h + 1
    listG = listG[::-1]
    m = len(listG)
    
    for g in listG:
        cnt = insertionSort(A, N, g, cnt)
        #print(A)
        
    print(m)
    print(" ".join(map(str, listG)))
    print(cnt)
    for v in A:
        print(v)

shellSort(A, N)
