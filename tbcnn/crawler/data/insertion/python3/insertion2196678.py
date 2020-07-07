def rren(): return list(map(int, input().split()))
N = int(input())
R = rren()

print(" ".join(map(str, R)))
for i in range(1,N):
    take = R[i]
    j = i-1
    while j >= 0 and R[j] > take:
        R[j+1] = R[j]
        j -= 1
    R[j+1] = take
    print(" ".join(map(str, R)))
