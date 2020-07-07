num = int(input(""))
seqs = list(map(int,input().split())) #แยกทุกตัวฝนบรรทัดแล้วเก็บค่าเป็น int 
count = 0
    #วน loop ตามจำนวนตัวเลขที่ input เข้ามาในบรรทัดแรก
for i in range(num): 
    #กำหนดให้ minindex = i ถ้ารอบแรกก็เป็น index ที่ 0 คือ เลขที่อยู่ตำแหน่งแรก
    minIndex = i 
    #วน loop ตามจำนวนตั้งแต่ 0-4 เพื่อใช้เป็นการดึง index
    #ของบรรทัดที่ input ข้อมูลตัวแรกเข้ามา
    for j in range(i,num):
    #ถ้าหากตำแหน่งที่ j น้อยกว่าตำแหน่งที่ minindex ให้เปลี่ยนค่า minindex เป็น j
        if seqs[j] < seqs[minIndex]:
            minIndex = j
            
    #ถ้าตำแหน่ง minindex ไม่เท่ากับ i และ  seqs[j] >= seqs[minIndex]
    #ให้ทำการ swap สลับตำแหน่ง        
    if minIndex != i:
        seqs[i],seqs[minIndex]=seqs[minIndex],seqs[i]
        count+=1
    #แสดงผล sequence ทั้งหมดออกมาเป็น string รวมถึงแสดงผลว่าทำการ swap ไปกี่รอบ
print(" ".join(map(str, seqs)))
print(count)

