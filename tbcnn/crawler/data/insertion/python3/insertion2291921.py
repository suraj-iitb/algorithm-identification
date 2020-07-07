# coding: utf-8

def printls(ls):
    print(' '.join(map(str,ls)))
    
def main():
    trash = input()
    ls = list(map(int, input().split(' ')))

    for i in range(1, len(ls)):
        printls(ls)
        v = ls[i]
        for j in reversed(range(0, i)):
            if ls[j] > v:
                ls[j], ls[j+1] = ls[j+1], ls[j]

    printls(ls)
    
if __name__ == '__main__':
    main()
