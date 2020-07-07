import math
def merge(a, left, mid, right):
    global c
    n1 = mid - left
    n2 = right - mid
    l = a[left:left + n1]
    r = a[mid:mid + n2]
    l.append(10e10) #กำหนดขนาดจำนวนข้อมูล
    r.append(10e10)
    i = 0
    j = 0
    for k in range(left, right):
        c += 1
        if l[i] < r[j]:
            a[k] = l[i]
            i += 1
        else:
            a[k] = r[j]
            j += 1
    #แบ่งครึ่งข้อมูลไปเรื่อยๆจนสุด โดยถ้าจำนวนข้อมูลเป็นจำนวนคี่ ก็ให้แบ่งครึ่งด้านซ้ายมากกว่าด้านขวาเสมอ
def mergeSort(a, left, right):
    if left + 1 < right:
        mid = math.ceil((left + right) / 2)
        mergeSort(a, left, mid)
        mergeSort(a, mid, right)
    #ทำการ merge sort
        merge(a, left, mid, right)

    #รับ input
n = int(input())
a = list(map(int,input().split()))
c = 0
    #เรียก fn
mergeSort(a, 0, n)
    #แสดงผล
print(" ".join(map(str, a)))
print(c)

