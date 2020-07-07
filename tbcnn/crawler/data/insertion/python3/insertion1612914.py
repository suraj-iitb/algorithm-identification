import sys

def display(inp):
    s = len(inp)
    for i in range(s):
        if i!=len(inp)-1:
            print("%d" % inp[i], end=" ")
        else:
            print("%d" % inp[i], end="")
    print("")

line = sys.stdin.readline()
size = int(line)
line = sys.stdin.readline()
inp = []
for i in line.split(" "):
    inp.append(int(i))

display(inp)

for i in range(1,size):
    if inp[i]!=size:
        check = inp.pop(i)
        for j in range(i):
            if check<inp[j]:
                inp.insert(j,check)
                break
            if j==i-1:
                inp.insert(j+1,check)
                break
    display(inp)
