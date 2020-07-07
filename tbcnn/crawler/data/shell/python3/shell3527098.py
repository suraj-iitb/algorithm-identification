import math

def solution(count,nums,g,oppai):
    for i in range(g,count):
        objNum = nums[i]
        j = i - g
        while j >= 0 and nums[j] > objNum:
            nums[j+g] = nums[j]
            j -= g
            oppai.append(1)
        nums[j+g] = objNum

def shellSort(nums,count):
    oppai = []
    b = 701
    G = [x for x in [1,4,10,23,57,132,301,701] if x <= count]
    while True:
        b = math.floor(2.25*b)
        if b > n:
            break
        G.append(b)
    G = G[::-1]
    print(len(G))
    print(' '.join(map(str,G)))
    for i in range(len(G)):
        solution(count,nums,G[i],oppai)
    print(len(oppai))
    for ele in nums:
        print(ele)

n = int(input())
nums = []


for _ in range(n):
    nums.append(int(input()))
shellSort(nums,n)

