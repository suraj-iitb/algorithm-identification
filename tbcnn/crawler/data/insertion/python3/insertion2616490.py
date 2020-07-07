def main() :
    n = int(input())
    lst = [int(i) for i in input().split()]

    print(" ".join(map(str, lst)));

    for i in range(1,n) :
        for j in reversed(range(i+1)) :
            if j == 0 :
                break
            elif lst[j] < lst[j-1]:
                lst[j], lst[j-1] = lst[j-1], lst[j]
        print(" ".join(map(str, lst)))






if __name__ == '__main__' :
    main()
