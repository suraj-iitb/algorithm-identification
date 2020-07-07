def print_list(A):
    for x in range(len(A) - 1):
        print(A[x],end = " ")
    print(A[len(A) - 1])

def insertionsort(A,n):
    count = 0
    for i in range(1,n):
        print_list(A)
        right = i
        left = i - 1
        while A[left] > A[right] and left >= 0:
            A[left],A[right] = A[right],A[left]
            right = left
            left -= 1
            count += 1
    print_list(A)
    return A

if __name__ == '__main__':
    n = int(input())
    A = [int(i) for i in input().split()]
    A = insertionsort(A,n)

