def selectionSort(A, N):
    count = 0
    # preA = copy.deepcopy(A)
    for i in range(N):
        minj = i
        for j in range(i, N):
            if A[j] < A[minj]:
                minj = j
        A[i], A[minj] = A[minj], A[i]
        
        if i != minj:
            count += 1
        # if A != preA:
        #     count += 1
        # preA = copy.deepcopy(A)
        
    return count

def main():
    N = int(input())
    list = input().split(" ")
    list = [int(s) for s in list]
    
    count = selectionSort(list, N)

    for i in range(len(list)):
        if i == len(list)-1:
            print(list[i])
        else:
            print(list[i], end=" ")

    print(count)

if __name__ == "__main__":
    main()
