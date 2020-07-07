# coding: utf-8

def bubblesort(ls):
    count = 0
    
    for i in range(1, len(ls)):
        for j in reversed(range(i, len(ls))):
            if ls[j] < ls[j-1]:
                ls[j], ls[j-1] = ls[j-1], ls[j]
                count += 1
    return count

def main():
    trash = input()
    ls = list(map(int, input().split(' ')))

    i = bubblesort(ls)

    print(' '.join((map(str,ls))))
    print(i)
    
if __name__ == '__main__':
    main()
