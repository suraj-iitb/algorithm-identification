INF = 10000000000

n = int(input())
A = [int(x) for x in input().split()]

def merge(A,left,mid,right):
    count = 0
    n1 = mid - left
    n2 = right - mid
    L = A[left:mid] + [INF]
    R = A[mid:right] + [INF]
    #L,Rの中身はAの中身の部分コピーだからいちいちappendするより
    #スライスしてまとめてコピーしたほうが処理が軽い
    #[INF]は番兵みたいなもの
    #[INF]を追加しておくとL,Rを調べつくしての
    #list index out of rangeを回避できる
    i, j = 0, 0
    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
    count += right - left
    return count

def mergeSort(A,left,right):
    if left + 1 < right:
        mid = int((left + right) / 2)
        countL = mergeSort(A,left,mid)
        countR = mergeSort(A,mid,right)
        return merge(A,left,mid,right) + countL + countR
    return 0

count = mergeSort(A,0,n)
for i in range(n):
    if i:
        print(" ",end="")
    print(A[i],end="")
print()
print(count)

