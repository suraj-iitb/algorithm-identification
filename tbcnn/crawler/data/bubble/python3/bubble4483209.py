n = int(input("")) #รับจำนวนข้อมูลในบรรทัดแรก
ns = list(map(int,input().split())) #รับข้อมูลในบรรทัดที่2 split และเก็บไว้ใน int 
c = 0
for i in range(n-1): #วน n-1 เพราะไม่นับรวมครั้งแรกที่ทำ
    for j in range(n-1-i): #วน loop 
        if ns[j] > ns[j+1]: #ถ้าข้อมูลในตำแหน่งที่ j > ข้อมูลตำแหน่งที่ j+1
            ns[j],ns[j+1]=ns[j+1],ns[j]
            #ทำการสลับตำแหน่ง j ไปที่ j+1 เหมือนฟองอากาศที่ลอยขึ้นไปเรื่อยๆ
            c+=1 # นับครั้งการ swap
print(" ".join(map(str,ns)))
print(c)


