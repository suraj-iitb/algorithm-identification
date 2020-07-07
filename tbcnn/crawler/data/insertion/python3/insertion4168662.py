num = int(input())
an = [ int(i) for i in input().split()]
print(" ".join([str(n) for n in an]))

for i in range(1, len(an)):
    v = an[i]
    j = i - 1
    while j >= 0 and an[j] > v:
      an[j+1] = an[j]
      j = j - 1
    
    an[j+1] = v

    print(" ".join([str(n) for n in an]))

