n = input()
data = [int(i) for i in input().split(' ')]

def insertion_sort(raw_list):
    for i, v in enumerate(raw_list):
        if i == 0:
            continue
        j = i - 1
        while j >= 0 and v < raw_list[j]:
            raw_list[j+1] = v 
            raw_list[j+1] = raw_list[j]
            j -= 1
        raw_list[j+1] = v 
        print(' '.join([str(i) for i in raw_list]))

    return raw_list

print(' '.join([str(i) for i in data]))
insertion_sort(data)
#print(' '.join([str(i) for i in insertion_sort(data)]))
