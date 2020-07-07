#โชว์การ sort ในแต่ละบรรทัด
def show (seqs):
    for i in range(len(seqs)):
        if i!=len(seqs)-1:
            print(seqs[i],end=' ')
        else :
            print(seqs[i])

num = int(input())
seqs = list(map(int,input().split()))

show(seqs) #โชว์ข้อมูลที่รับ input มา

for i in range(1,num):#วน loop เริ่มจาก 1 จนถึงจำนวนข้อมูล
    element = seqs[i] #ให้ element = ข้อมูลในตำแหน่งที่ i ซึ่ง iเป็นได้ 0ถึงจำนวนข้อมูล-1
    j = i-1 
    while (j>=0 and seqs[j]>element): #ถ้าข้อมูลตัวด้านซ้ายมีค่ามากกว่าข้อมูลที่อยู่ด้านขวา
        seqs[j+1] = seqs[j] # swap ข้อมูลที่น้อยที่สุดไปยังด้านซ้ายสุดเสมอ
        j -=1
    #ถ้าหลุด loop while ทำการเปลี่ยนขa้อมูลให้เป็นข้อมูลของตัวที่ได้สลับไปก่อนหน้านี้    
    seqs[j+1]=element
    show(seqs)

