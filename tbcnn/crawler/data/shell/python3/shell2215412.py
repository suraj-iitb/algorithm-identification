def insertionSort(A, n , g, in_cnt):
    lo_cnt = in_cnt
    for i in range(g, n):
        v = A[i]
        j = i - g
        while j>=0 and A[j]>v:
            A[j+g] = A[j]
            j = j - g
            lo_cnt = lo_cnt + 1
        A[j+g] = v
    return [A,lo_cnt]


A = []
G = []
data_num = int(input())
for i in range(data_num):
     A.append(int(input().rstrip()))

cnt = 0
gap = data_num
while True: 
    if gap > 1:
        gap = gap // 2

    G.append(gap)
    A, cnt = insertionSort(A, data_num, gap, cnt)
    if gap == 1:
        break
    
print(str(len(G)))
print(" ".join(map(str,G)))
print(str(cnt))
print("\n".join(map(str,A)))
