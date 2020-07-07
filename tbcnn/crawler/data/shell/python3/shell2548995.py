


def generateG(n):
    if n == 1:
        return [1]
    g = []
    h = 1
    while h < n:
        g.append(h)
        h = 3*h+1
    g.reverse()
    return g 

def insertionSort(a, n, g):
    cnt = 0
    for i in range(g, n):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j+g] = a[j]
            j = j - g
            cnt += 1
            
        a[j+g] = v
    return cnt

if __name__ == '__main__':
    N = (int)(input())
    A = []
    cnt = 0
    for x in range(N):
        A.append((int)(input()))

    g = generateG(N)

    count = 0

    for x in g:
        count += insertionSort(A,N,x)

    print(len(g))
    print(' '.join([(str)(x) for x in g]))
    print(count)
    print('\n'.join([(str)(x) for x in A]))
    
