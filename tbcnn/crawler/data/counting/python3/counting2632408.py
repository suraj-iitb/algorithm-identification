# coding=utf-8
def counting_sort(input_list: list, upper: int) -> list:
    number = len(input_list)

    # noinspection PyUnusedLocal
    b = [0 for i in range(number+1)]
    # noinspection PyUnusedLocal
    counter_list = [0 for i in range(upper+1)]

    for j in input_list:
        counter_list[j] += 1

    for i in range(k+1):
        counter_list[i] += counter_list[i-1]

    for j in range(number):
        b[counter_list[input_list[j]]] = input_list[j]
        counter_list[input_list[j]] -= 1

    return b


if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    k = 2000000
    a = counting_sort(a, k)
    a.pop(0)

    print(' '.join(map(str, a)))
