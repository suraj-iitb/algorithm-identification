#http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_A&lang=jp
#?¨???°?????????

def counting_sort(target_list):
    counter = [0 for i in range(10000)]

    for n in target_list:
        counter[n] += 1

    for i in range(1,10000):
        counter[i] = counter[i] + counter[i-1]

    result = [0 for i in range(len(target_list))]
    for n in target_list[::-1]:
        result[counter[n] - 1] = n
        counter[n] -= 1
    
    return result
if __name__ == "__main__":
    n_list = int(input())
    target_list = [int(s) for s in input().split()]
    sorted_list = counting_sort(target_list)
    print(" ".join([str(s) for s in sorted_list]))
