count = int(input());
data = [int(n) for n in input().split(" ")];

def bubble_sort(data):
    count = len(data);
    o = 0;
    for i in range(count):
        for j in range(count - 1, i, -1):
            if data[j] < data[j - 1]:
                o += 1;
                temp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = temp;
    show(data);
    print(o);

def show(data):
    print(" ".join(str(n) for n in data));

bubble_sort(data);
