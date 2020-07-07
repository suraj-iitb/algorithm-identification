import math

class MergeSort:
    cnt = 0
    def merge(self, a, n, left, mid, right): 
        n1 = mid - left
        n2 = right - mid
        l = a[left:(left+n1)]
        r = a[mid:(mid+n2)]
        l.append(2000000000)
        r.append(2000000000)
        i = 0
        j = 0
        for k in range(left, right):
            self.cnt += 1
            if l[i] <= r[j]:
                a[k] = l[i]
                i += 1
            else:
                a[k] = r[j]
                j += 1
        return a
        
    def mergeSort(self, a, n, left, right):
        if left + 1 < right:
            mid = (left + right) // 2
            self.mergeSort(a, n, left, mid)
            self.mergeSort(a, n, mid, right)
            self.merge(a, n, left, mid, right)
        return a

if __name__ == '__main__':
    n = int(input().rstrip())
    s = [int(i) for i in input().rstrip().split(" ")]
    x = MergeSort()
    print(" ".join(map(str, x.mergeSort(s, n, 0, n))))
    print(x.cnt)
