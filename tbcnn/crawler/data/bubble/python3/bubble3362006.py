def bubbleSort(a, n):   #n個の要素を持つ配列a
    flag = 1    #逆の隣接要素あり
    i = 0       #未ソートの先頭
    count = 0
    while flag:
        flag = 0
        for j in range(n-1, i, -1): #j n-1...i+1
            if a[j] < a[j-1]:

                a[j], a[j-1] = a[j-1], a[j]
                count += 1
                flag = 1
        i += 1
    print(' '.join(map(str, a)))
    print(count)


#配列出力用
def trace(a, n):
    output = ''
    for i in a:
        if i == a[n-1]:
            output += str(i)
        else:
            output += str(i) + ' '
    print(output)

#配列の要素数と要素の入力
n = int(input())
a = list(map(int, input().split()))

bubbleSort(a, n)
