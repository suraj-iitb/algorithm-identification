import sys
#import time

compare_counter = 0
array = [0 for x in range(500000)]

def merge(left, mid, right):
    n_fore = mid - left
    n_rear = right - mid
    l_fore = array[left:left + n_fore]
    l_fore.append(sys.maxsize)
    l_rear = array[mid:mid + n_rear]
    l_rear.append(sys.maxsize)

    #print(left, mid, right)
    i = j = 0
    global compare_counter
    compare_counter += (right - left)
    for k in range(left, right):
        if l_fore[i] < l_rear[j]:
            array[k] = l_fore[i]
            i += 1
        else:
            array[k] = l_rear[j]
            j += 1


def merge_sort(left, right):
    if left + 1 < right:
        mid = (left + right) // 2
        merge_sort(left, mid)
        merge_sort(mid, right)
        merge(left, mid, right)
    return


def main():
    #start = time.time()
    n = int(input())
    for idx, tmp in enumerate(input().split()):
        array[idx] = int(tmp)
    #print("time", time.time()-start)
    merge_sort(0, n)
    #print("time", time.time()-start)
    print(" ".join(map(str, array[:n])))
    print(compare_counter)
    #print("time",time.time()-start)
    return


main()
