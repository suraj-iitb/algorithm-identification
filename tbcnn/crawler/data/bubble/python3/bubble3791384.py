num_inputs = int(input())
array = input().split(' ')
flag = True
count = 0

while flag:
    flag = False
    for i in reversed(range(1, num_inputs)):
        if int(array[i]) < int(array[i - 1]):
            buf = array[i]
            array[i] = array[i - 1]
            array[i - 1] = buf
            count += 1
            flag = True

print(' '.join(array))
print(str(count))
