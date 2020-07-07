N = int(input())
A = list(map(int, input().split()))


def bubble_sort(Ary):
    N = len(Ary)
    tento_su = 0
    flag = 1 # 0->整列済み
    while flag == 1: 
        flag = 0
        for i in range(N-1):
            if Ary[-1-i]<Ary[-2-i]:
                X = Ary[-1-i]
                Ary[-1-i] = Ary[-2-i]
                Ary[-2-i] = X
                flag = 1
                tento_su += 1
    return Ary, tento_su

A_sorted , tento_su = bubble_sort(A)
print(' '.join(map(str, A_sorted)))
print(tento_su)

