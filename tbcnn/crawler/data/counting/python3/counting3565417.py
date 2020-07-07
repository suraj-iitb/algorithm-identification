from sys import stdin

def counting_sort(nums, k):
    out = [0] * len(nums)
    cnts = [0] * (k + 1)
    offsets = [0] * (k + 1)
    for n in nums:
        cnts[n] = cnts[n] + 1
    
    for i in range(len(cnts)):
        if i > 0:
            offsets[i] = offsets[i - 1] + cnts[i - 1]
    
    for n in nums:
        out[offsets[n]] = n
        offsets[n] = offsets[n] + 1
    return out

def main():
    lines = stdin.readlines()
    nums = list(map(int, lines[1].split(' ')))
    n_max = max(nums)
    sorted_nums = counting_sort(nums, n_max)
    print(' '.join(map(str, sorted_nums)))

if __name__ == '__main__':
    main()
