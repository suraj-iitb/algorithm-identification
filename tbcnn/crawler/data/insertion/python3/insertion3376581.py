# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_A&lang=jp

def insertion_sort(array):
    putsarray(array)
    N = len(array)
    for i in range(1, N):
        j = i - 1
        num = array[i]
        while j >= 0 and array[j] > num:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = num
        putsarray(array)

def putsarray(array):
    for i in range(len(array) - 1):
        print(array[i], end=" ")
    print(array[-1])


N = int(input())
array = input().split()
array = [int(n) for n in array]
insertion_sort(array)



