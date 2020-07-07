num = int(input())
num_array = input().split(" ")

for i in range(num):
    num_array[i] = int(num_array[i])


def put_array():
    for i in range(num):
        print(num_array[i], end="")
        if i != num-1:
            print(" ", end="")
        else:
            print("")

def insertionSort(A, N):
    for i in range(1, N):
        put_array()
        v = A[i]
        j = i - 1
        while j >= 0 and A[j] > v:
            A[j+1] = A[j]
            j -= 1
        A[j+1] = v


if __name__ == "__main__":

    insertionSort(num_array, num)

    put_array()
