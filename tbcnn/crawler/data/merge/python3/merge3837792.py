class MergeSort:
    def __init__(self, array):
        self._arr = array
        self._cnt = 0

    def _merge(self, left, mid, right):
        arr1 = self._arr[left:mid] + [float('inf')]
        arr2 = self._arr[mid:right] + [float('inf')]

        i, j = 0, 0
        for k in range(left, right):
            if arr1[i] <= arr2[j]:
                self._arr[k] = arr1[i]
                i += 1
            else:
                self._arr[k] = arr2[j]
                j += 1

        self._cnt += right - left
        return

    def _merge_sort(self, left, right):
        if right <= left + 1:
            return

        mid = (left + right) // 2
        self._merge_sort(left, mid)
        self._merge_sort(mid, right)
        self._merge(left, mid, right)
        return

    def sort(self):
        self._merge_sort(0, len(self._arr))
        return

    def print(self):
        print(*self._arr)
        print(self._cnt)

n = int(input())
arr = [int(s) for s in input().split()]

alg = MergeSort(arr)
alg.sort()
alg.print()

