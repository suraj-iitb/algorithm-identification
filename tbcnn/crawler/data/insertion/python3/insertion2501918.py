def output(list):
    for i,row in enumerate(list):
        if i == 0:
            print(row,end='')
        else:
            print('',row,end='')
    
def main():
    s = input()
    s_list = []
    s_list = list(map(int,input().split()))

    output(s_list)
    print()

    i = 0
    for count in range(len(s_list)-1):

#   Judge: now > next
        if s_list[i] > s_list[i+1]:

#       Change: now > next
            ins_num = s_list[i+1]
            s_list[i+1] = s_list[i]
            s_list[i]   = ins_num

            j = i - 1

            while j >= 0:
                if s_list[j] > ins_num:
                    s_list[j+1] = s_list[j]
                    s_list[j]   = ins_num

                j -= 1
            output(s_list)
        else:
           output(s_list)        
    
        print()
        i += 1

if __name__ == '__main__':
    main()
