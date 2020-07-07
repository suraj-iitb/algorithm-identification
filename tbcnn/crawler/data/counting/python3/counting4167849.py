#初期値
n_max = 2000000
a_max = 10000

#インプットdata
input_n = int(input())
input_a = list(map(int, input().split()))
output = list()

#カウンタ配列Cの作成
c_list = [0] * (a_max + 1)
for i in input_a:
    c_list[i] += 1
for i in range(1, a_max+1):
    c_list[i] += c_list[i-1]

#ソートリスト作成
sort_list = [0 for i in range(input_n)]
for i in range(input_n-1, -1, -1):
    sort_list[c_list[input_a[i]]-1] = input_a[i]
    c_list[input_a[i]] -= 1

#結果表示
print(" ".join(map(str, sort_list)))
