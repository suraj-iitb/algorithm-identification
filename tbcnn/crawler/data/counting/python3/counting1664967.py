class CountingSort:
    def countingSort(self, a, b, k):
        n = len(a)
        c = [0] * (k + 1)
        for j in a:
            c[j] += 1
        
        for i in range(1, k + 1):
            c[i] = c[i] + c[i-1]
            
        for j in a[::-1]:
            b[c[j]] = j
            c[j] -= 1
        return b[1:]

if __name__ == '__main__':
    n = int(input().rstrip())
    a = [int(i) for i in input().rstrip().split(" ")]
    b = [0] * (n + 1)
    k = max(a)
    x = CountingSort()
    print(" ".join([str(i) for i in x.countingSort(a, b, k)]))
