
def InsertionSort(l):
    print(" ".join(map(str, l)))
    
    for idx in range(1, len(l)):
        jdx = idx - 1
        while jdx >= 0 and l[idx] < l[jdx]:
            l[jdx], l[idx] = l[idx], l[jdx]
            idx -= 1
            jdx -= 1

        print(" ".join(map(str, l)))

def main():
    _ = input()
    in_list = list(map(int, input().split(' ')))
    
    InsertionSort(in_list)


main()
