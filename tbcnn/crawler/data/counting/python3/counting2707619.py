def cSort(hoge, k):
    sorted_list = [0] * (len(hoge)-1)
    sorted_list.insert(0, None)
    count_list = [0] * (k+1)
    for i in range(1, len(hoge)):
        count_list[hoge[i]] += 1
    
    for i in range(1, len(count_list)):
        count_list[i] = count_list[i] + count_list[i-1]
    
    for j in range(1, len(hoge))[::-1]:
        sorted_list[count_list[hoge[j]]] = hoge[j]
        count_list[hoge[j]] -= 1
    
    sorted_list.remove(None)
    return sorted_list
    
if __name__ == '__main__':
    _ = input()
    hoge = [int(x) for x in input().split()]
    max_num = max(hoge)
    hoge.insert(0, None)
    print (' '.join([str(x) for x in cSort(hoge, max_num)]))
