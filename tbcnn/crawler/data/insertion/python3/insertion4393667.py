N = int(input())
list_cards = [0]*N
list_cards = list(map(int,input().split()))

def insertionsort(A, N):
    for i in range(N):
        v = A[i]
        j = i-1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v        

        A_str = list(map(str, A))
        print(" ".join(A_str))

    return(A)

result_cards = insertionsort(list_cards, N)

