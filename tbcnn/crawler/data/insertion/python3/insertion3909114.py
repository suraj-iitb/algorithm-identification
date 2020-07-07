n = int(input())
NUM_STR = input()

print(NUM_STR)

NUM_LIST = list(map(int, NUM_STR.split()))

for i in range(1, len(NUM_LIST)):
    v = NUM_LIST[i]
    j = i - 1
    while NUM_LIST[j] > v and j >= 0:
        NUM_LIST[j+1] =NUM_LIST[j]
        j -= 1
    NUM_LIST[j+1] = v
    STR = list(map(str, NUM_LIST))
    print(" ".join(STR))
