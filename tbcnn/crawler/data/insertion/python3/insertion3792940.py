def main():
    n = int(input())
    al = list(map(int, input().split(' ')))
    
    for i in range(n):
        v = al[i]
        j = i - 1
        while j >= 0 and al[j] > v:
            al[j + 1] = al[j]
            j -= 1
        al[j + 1] = v
        print(' '.join(list(map(str, al))))


if __name__ == '__main__':
    main()
