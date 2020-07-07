#http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_B&lang=jp
sentinel = pow(10,9) + 1
def merge(target_list, left_index, mid_index,right_index):
    
    l = target_list[left_index:mid_index] + [sentinel]
    r = target_list[mid_index:right_index] + [sentinel]
    l_target, r_target, count = 0, 0, 0
    #print(left_index, right_index, mid_index, l,r)
    for k in range(left_index, right_index):
        if l[l_target] < r[r_target]:
            target_list[k] = l[l_target]
            l_target += 1
        else:
            target_list[k] = r[r_target]
            r_target += 1

    return l_target + r_target
    #print(target_list)
            
def merge_sort(target_list, left_index, right_index):
    count = 0
    if left_index + 1 < right_index:
        mid_index = (left_index + right_index) // 2

        count += merge_sort(target_list, left_index, mid_index)
        count += merge_sort(target_list, mid_index, right_index)
        count += merge(target_list, left_index, mid_index,right_index)
        
    return count
if __name__ == "__main__":
    l = input()
    target_list = [int(a) for a in input().split()]
    count = merge_sort(target_list, 0, len(target_list))
    print(" ".join([str(n) for n in target_list]))
    print(count)
