import sys
input = sys.stdin.readline

def insertion_sort(n,a):
    for i in range(n):
        v = a[i]
        j = i - 1
        while j >= 0 and a[j] > v:
            a[j+1] = a[j]
            j -= 1
        a[j+1] = v
        print(' '.join(map(str,a)))
    return a
    
if __name__ == "__main__":
    n = int(input())
    a = list(map(int,input().split()))
    insertion_sort(n,a)

