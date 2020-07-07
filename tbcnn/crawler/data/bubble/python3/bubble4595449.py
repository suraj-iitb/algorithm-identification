from sys import stdin

def bubble_sort(A, N):
    flg = 1
    count = 0
    while flg:
        flg = 0
        for i in range(N-1,0,-1):
            if A[i] < A[i-1]:
                A[i], A[i-1] = A[i-1], A[i]
                flg = 1
                count += 1
    return count
                
    
def main():
    read = stdin.readline
    N = int(read())
    data = list(map(int, read().split(" ")))
    count = bubble_sort(data, N)
    for i in range(N-1):
        print(data[i], end = " ")
    print(data[N-1])
    print(count)
    
    
if __name__ == "__main__":
    main()
