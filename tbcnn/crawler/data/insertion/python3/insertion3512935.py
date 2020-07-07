n = int(input())
given_array = [int(x) for x in input().split()]

for i in range(1,n):
    print(" ".join([str(x) for x in given_array]))
    key = given_array[i]
    j = i - 1
    while j >= 0 and given_array[j] >= key:
        temp = given_array[j]
        given_array[j] = given_array[j+1]
        given_array[j+1] = temp
        j -= 1

    given_array[j+1] = key

print(" ".join([str(x) for x in given_array]))

