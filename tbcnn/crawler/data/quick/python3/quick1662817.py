class Quicksort:
    def quicksort(self, a, p, r):
        if p < r:
            q = self.partion(a, p, r)
            self.quicksort(a, p, q - 1)
            self.quicksort(a, q + 1, r)
        return(a)

    def partion(self, a, p, r): 
        x = a[r][1]
        i = p - 1
        for j in range(p, r):
            if a[j][1] <= x:
                i += 1
                a[i], a[j] = a[j], a[i]
        a[i + 1], a[r] = a[r], a[i + 1]
        return(i+1)

def bubbleSort(a, n):
    flag = 1
    while flag == 1:
        flag = 0
        for j in range(n-1, 0, -1):
            if a[j][1] < a[j - 1][1]:
                a[j], a[j-1] = a[j-1], a[j]
                flag = 1
    return(a)

if __name__ == '__main__':
    n = int(input().rstrip())
    cards = []
    for i in range(n):
        tmp = input().rstrip().split(" ")
        tmp[1] = int(tmp[1])
        cards.append(tmp)
    a = cards[:]
    b = cards[:]
    x = Quicksort()
    a = x.quicksort(a, 0, n-1)
    b = sorted(b, key=lambda i: i[1])
    
    if a == b:
        print("Stable")
    else:
        print("Not stable")
    
    for i in a:
        i[1] = str(i[1])
        print(" ".join(i))
