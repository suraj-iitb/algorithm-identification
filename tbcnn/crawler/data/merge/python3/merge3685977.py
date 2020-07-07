#前の問題で、戻り値とかIDとか変更したつもりのリストが変わっていないことが
#頻発していたはずだがとりあえず並び替え自体は終わる。countどうしようか。
#いじると並び替え前の配列が返ってくることがある。

n=int(input())
A1=input().split( )
A=[int(A1[i]) for i in range(n)]
###疑似コードのコピペ
def merge(A, left, mid, right):
    n1 = mid - left;
    n2 = right - mid;
#いちいち[0 for i...]を作るのやめた
    L=A[left:mid]+[10000000000]
    R=A[mid:right]+[10000000000]
    
    i = 0
    j = 0
    count=0

    for k in range(left,right):
        count+=1
        if L[i] <= R[j]:
            A[k] = L[i]
            i = i + 1
        else:
            A[k] = R[j]
            j = j + 1

#count+=1の位置を変更,比較ってinfinityとの比較も含めるのか
#計算量的には当然か。
    return(count)

def mergeSort(A, left, right):
    count=0
    mid=0
    if left+1 < right:
        mid = int((left + right)/2)
#この辺で新しい変数をmergeSortの戻り値として定義
        countL=mergeSort(A, left, mid)
        countR=mergeSort(A, mid, right)
        countM=merge(A, left, mid, right)
        count=countL+countR+countM
    return(count)
c=mergeSort(A,0,n)
print(*A)
print(c)

