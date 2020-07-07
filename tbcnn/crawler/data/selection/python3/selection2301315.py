def main():
    tmp = input()
    ls = list(map(int, input().split(' ')))
    count = 0
    
    for i in range(len(ls)):
        minj = i
        
        for j in range(i, len(ls)):
            if ls[j] < ls[minj]:
                minj = j
        ls[i], ls[minj] = ls[minj], ls[i]

        if minj != i:
            count += 1

    print(' '.join(map(str,ls)))
    print(count)
    
if __name__ == '__main__':
    main()
