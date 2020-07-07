
def BubleSort(l):
    cnt = 0

    for idx in range(len(l), 0, -1):
        for jdx in range(1, idx):
            if l[jdx] < l[jdx-1]:
                l[jdx-1], l[jdx] = l[jdx], l[jdx-1]
                cnt += 1

    print(" ".join(map(str, l)))
    print(cnt)

def main():
    _ = input()
    in_list = list(map(int, input().split(' ')))
    BubleSort(in_list)

main()
