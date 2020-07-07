count = int(input());
data = [int(n) for n in input().split(" ")];

def selection_sort(data):
    count = len(data);
    o = 0;
    for i in range(count):
        minI = i;
        for j in range(i + 1, count):
            if data[j] < data[minI]:
                minI = j;
        if minI != i:
            temp = data[i];
            data[i] = data[minI];
            data[minI] = temp;
            o += 1;
    show(data);
    print(o);

def show(data):
    print(" ".join(str(n) for n in data));

selection_sort(data);
