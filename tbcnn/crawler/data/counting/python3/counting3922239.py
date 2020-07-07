"""
7
2 5 1 3 2 3 0
"""

def counting_sort(A, n, max):
    B = [0] * n
    C = [0] * (max + 1)
    # print(B)
    # print(C)

    for j in range(n):
        C[A[j]] += 1
    # print(C)

    for i in range(1, max+1):
        # print(i)
        C[i] = C[i] + C[i-1]
    # print("A", A)
    # print("B", B)
    # print("C", C)

    for j in reversed(range(n)):
        # print(j)
        # # print(j)
        # print(A[j])
        # print(C[A[j]])
        B[C[A[j]]-1] = A[j]
        # print(B)
        C[A[j]] -= 1

    B_str = []
    for b in B:
        B_str.append(str(b))
    print(" ".join(B_str))
    

if __name__=="__main__":
    n = int(input())
    A = list(map(int, input().split()))
    max = max(A)
    counting_sort(A, n, max)
    # print(B)
    # B_str = []
    # for b in B:
    #     B_str.append(str(b))
    # print(" ".join(B_str))
