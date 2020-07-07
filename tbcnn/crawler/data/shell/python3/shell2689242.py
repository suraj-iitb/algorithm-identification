count = int(input());
data = [];
for i in range(count):
    data.append(int(input()));
gaps = [1];
for i in range(99):
    next_gap = 3 * gaps[-1] + 1;
    if count > next_gap:
        gaps.append(next_gap);
    else:
        break;
gaps.reverse();

def shell_sort(data, gaps):
    o = 0;
    for gap in gaps:
        for g in range(gap):
            o += insert_sort(data, gap, g);
    return o;

def insert_sort(data, gap, g):
    o = 0;
    count = len(data);
    for i in range(g + gap, count, gap):
        n = data[i];
        j = i - gap;
        while j >= 0:
            if data[j] > n:
                o += 1;
                data[j + gap] = data[j];
                j -= gap;
            else:
                break;
        data[j + gap] = n;
    return o;

o = shell_sort(data, gaps);

print(len(gaps));
print(" ".join(str(n) for n in gaps));
print(o);
print("\n".join(str(n) for n in data));
