def main():
    num = int(input())
    sort_nums = list(map(int, input().split()))
    
    min_num_index = 0
    temp_counter = 0
    for i in range(0, num):
        min_num_index = i
        for j in range(i, num):
            if sort_nums[j] < sort_nums[min_num_index]:
                min_num_index = j

        if not sort_nums[i] == sort_nums[min_num_index]:
            temp_counter += 1

            temp = sort_nums[i]
            sort_nums[i] = sort_nums[min_num_index]
            sort_nums[min_num_index] = temp
        
    print(" ".join([str(n) for n in sort_nums]))
    print(temp_counter)

if __name__ == '__main__':
    main()
