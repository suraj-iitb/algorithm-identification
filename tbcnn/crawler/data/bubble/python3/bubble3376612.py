# http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A&lang=jp
def bubble_sort(array):
    N = len(array)
    is_reversed_items_exist = True
    reverse_time = 0

    while  is_reversed_items_exist:
        is_reversed_items_exist = False
        for i in range(N - 1):
            if array[i] > array[i + 1]:
                array[i], array[i + 1] = array[i + 1], array[i]
                is_reversed_items_exist = True
                reverse_time += 1
    return reverse_time
    
def putsarray(array):
    for i in range(len(array) - 1):
        print(array[i], end=' ')
    print(array[-1])

if __name__ == "__main__":
    N = int(input())
    array = input().split()
    array = [int(n) for n in array]
    reverse_time = bubble_sort(array)
    putsarray(array)
    print(reverse_time)
