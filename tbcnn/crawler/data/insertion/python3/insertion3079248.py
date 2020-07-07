N = int(input())
A =  list(map(int, input().split())) 

def output_ary():

    s = ''

    for x in A:

        s = s + str(x) + ' '
    
    print(s.rstrip())

output_ary()

i = 1

while i < N:

    V = A[i]

    j = i - 1

    while j >= 0 and A[j] > V:

        A[j + 1] = A[j]
        
        j -= 1
    
    A[j + 1] = V

    i += 1

    output_ary()

