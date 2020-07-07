def insertionSort(lis,leng):
    for i in range(leng):
        v = lis[i]
        j = i - 1
        while j >= 0 and lis[j] > v:
            lis[j+1] = lis[j]
            j = j-1
        lis[j+1]=v
        print(*lis)

        
if __name__ == "__main__":
    lengg=int(input())
    liss=list(map(int, input().split()))
    insertionSort(liss,lengg)
