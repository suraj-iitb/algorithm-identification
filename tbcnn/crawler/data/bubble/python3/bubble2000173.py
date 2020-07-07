import sys

def bubble_sort(n, data):
    flag = True
    i = 0
    cnt = 0

    while flag:
        flag = False
        
        for j in range(n-1, i, -1):
            if data[j] < data[j-1]:
                data[j], data[j-1] = data[j-1], data[j]
                cnt += 1
                flag = True

        i += 1

    print(' '.join([str(i) for i in data]))
    print(cnt)
        
def main():
    n = int(sys.stdin.readline().strip())
    data = [int(i) for i in sys.stdin.readline().strip().split(' ')]
    bubble_sort(n, data)
    
if __name__ == '__main__':
    main()
    
