num_inputs = int(input())
input_array = input().split(' ')

for i in range(1, num_inputs):
    print(' '.join(input_array))
    current_value = input_array[i]
    j = i - 1
    while j >= 0 and int(input_array[j]) > int(current_value):
        input_array[j + 1] = input_array[j]
        j -= 1
    input_array[j + 1] = current_value
    
print(' '.join(input_array))
