# ?????\?????????????????°??????
import sys

def print_data(data):
    last_index = len(data) - 1
    
    for idx, item in enumerate(data):
        print(item, end='')
        if idx != last_index:
            print(' ', end='')

    print('')
        
def main():
    n = int(sys.stdin.readline().strip())
    data = [int(i) for i in sys.stdin.readline().strip().split(' ')]
    print_data(data)
    
    for i in range(1, n):
        v = data[i]
        j = i - 1

        while j >= 0 and data[j] > v:
            data[j+1] = data[j]
            j -= 1

        data[j+1] = v
        print_data(data)
            
if __name__ == '__main__':
    main()
