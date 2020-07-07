n = int(input())
a = []
for i in range(n): #วน loop รับ input แต่ละบรรทัด
    a.append(int(input()))

def insertionsort(a, n, g): #ทำการ insertion sort โดยใช้ gap
    global c
    for i in range(g, n):
        v = a[i]
        j = i - g
        while j >= 0 and a[j] > v:
            a[j + g] = a[j]
            j = j - g
            c += 1
        a[j + g] = v

c = 0
g = [1]
while g[-1] * 3 + 1 < n: #สูตรในการหา gap จากจำนวนข้อมูล ถ้ามี 5 gap ก็จะเป็น 4 และ 1 
    g.append(g[-1] * 3 + 1)
g.reverse() #ทำการเปลี่ยนให้เป็น 1,4 เรียงข้อมูล

for i in range(len(g)):#วน loop ทำตามรอบของจำนวน gap 
    insertionsort(a, n, g[i])
    #ทำการแสดงผล output แบบ เป็นบรรทัดตามโจทย์
print(len(g))
print(" ".join(map(str, g)))
print(c)
for i in range(n):
    print(a[i])

