def insertion_sort(target_list):
    sorted_list = list()
    for target in target_list[:]:
        for i, num in enumerate(sorted_list):
            if num > target:
                sorted_list[i:i] = [target]
                break
        else:
            sorted_list.append(target)
        target_list.pop(0)
        print(' '.join(str(s) for s in sorted_list + target_list))

N = int(input())
A = [int(s) for s in input().split()]
insertion_sort(A)
