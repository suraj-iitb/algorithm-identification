
def insertionSort(S, N):
    for i in range(N):
        v = S[i]
        j = i-1
        while j >= 0 and S[j] > v:
            S[j+1] = S[j]
            j = j-1
        S[j+1] = v
        
        print(' '.join(map(str, S)))
        
        
n = int(input())
s = list(map(int, input().split()))
insertionSort(s, n)
