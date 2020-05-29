import matplotlib.pyplot as plt

x1 = []
y1 = []
x2 = []
y2 = []

with open('time_heap.txt') as h:
    with open('time_merge.txt') as m:
        
        for i in zip(h,m):
        
            i1 = i[0].strip().split(' ')
            i2 = i[1].strip().split(' ')
    
            x1.append(int(i1[0]))
            y1.append(float(i1[1]))
            x2.append(int(i2[0]))
            y2.append(float(i2[1]))
        
        # print(x1,y1)
        # print(x2,y2)
        plt.plot(x1, y1, label="Heap Sort")
        plt.plot(x2, y2, label="Merge Sort")
        plt.ylabel('Time (in ms)')
        plt.xlabel('n')
        plt.legend()
        plt.savefig('raw.png')
            
            