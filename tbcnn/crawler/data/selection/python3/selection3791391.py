num_inputs = int(input())
array = input().split(' ')
count = 0

for i in range(num_inputs):
    minj = i
    for j in range(i, num_inputs):
        if int(array[j]) < int(array[minj]):
            minj = j
    
    if minj != i:
        buf = array[i]
        array[i] = array[minj]
        array[minj] = buf
        count += 1

print(' '.join(map(str, array)))
print(str(count))
