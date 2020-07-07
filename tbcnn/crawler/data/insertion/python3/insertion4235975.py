def insertionSort(self,len):
    for i in range(1,len,1):
        print(*self)
        v = self[i] #2
        j = i - 1
        while j >= 0 and self[j] > v:
            self[j+1] = self[j]
            j-=1
            self[j+1] = v
    print(*self)
numslen = int(input())
nums = [int(e) for e in input().split()]
insertionSort(nums,numslen)
