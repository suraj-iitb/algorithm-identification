# Sort II - Counting Sort
def	countingSort(A,n,k):
    result = []
    # Prepare Bucket
    C = [0]*(k+1)
    # Throw number into bucket
    for a in A:
        C[a] += 1
    # Pick up index from first in order
    for i,c in enumerate(C):
        while c > 0:
            result.append(i)
            c -= 1
    return result

n = int(input())
A = list(map(int, input().split()))
k = max(A)
B = countingSort(A,n,k)
print(*B)
