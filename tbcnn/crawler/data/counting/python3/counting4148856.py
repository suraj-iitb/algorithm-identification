def counting_sort():
    input()
    C = [0]*(10000+1)
    b = []
    for a in map(int, input().split()):
        C[a] += 1
    for i, c in enumerate(C):
        b += [str(i)]*c
    print(' '.join(b))
        
if __name__ == "__main__":
    counting_sort()
