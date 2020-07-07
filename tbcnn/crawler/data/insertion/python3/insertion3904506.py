def insertion_sort(array):
    n = len(array)
    for i in range(1, n):
        tmp = array[i] # 挿入する値を退避
        if tmp < array[i-1]:
            # 挿入する位置までずらしていく
            j = i
            while True:
                array[j] = array[j-1]
                j -= 1
                if j == 0 or tmp >= array[j-1]:
                    break
            array[j] = tmp 
        print_list(array)

def print_list(array):
    list_s = [str(x) for x in array]
    print(" ".join(list_s))


N = int(input())
A = list(map(int, input().split()))
print_list(A)
insertion_sort(A)
#print_list(A)
