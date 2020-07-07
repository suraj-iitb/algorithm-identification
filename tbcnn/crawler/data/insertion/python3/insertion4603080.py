num = int(input())
num_list = list(map(int, input().split()))
for i in range(len(num_list)):
        if i != len(num_list) - 1:
            print(num_list[i],end=" ")
        else:
            print(num_list[i])

for i in range(1, num):
    v = num_list[i]
    j = i - 1
    while j >= 0 and v < num_list[j]:
        num_list[j + 1] = num_list[j]
        j -= 1
    num_list[j + 1] = v
    #print(num_list)
    for i in range(len(num_list)):
        if i != len(num_list) - 1:
            print(num_list[i],end=" ")
        else:
            print(num_list[i])
    
