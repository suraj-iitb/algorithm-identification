count = int(input());
data = [int(n) for n in input().split(" ")];

def insert_sort(data):
    show(data);
    for i in range(1, len(data)):
        n = data[i];
        j = i - 1;
        while j >= 0 and data[j] > n:
            data[j + 1] = data[j];
            j -= 1;
        data[j + 1] = n;
        show(data);

def show(data):
    print(" ".join(str(n) for n in data));

insert_sort(data);
