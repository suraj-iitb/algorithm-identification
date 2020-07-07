def insertitionSort(A,N):
    for i in range(N):
        v = A[i]
        j = i -1
        
        while j>=0 and A[j] > v:
            A[j+1] = A[j]
            j = j -1
        A[j+1] = v
        map_result = map(str, A)
        print(' '.join(map_result))                  ### 出力形式を変換

##from IPython.core.debugger import Pdb; Pdb().set_trace()        
N = int(input())
A = list(map(int, input().split()))   ###　　1行の複数の入力を整数型で

insertitionSort(A,N)



