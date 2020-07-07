N = int(input())
A =  list(map(int, input().split())) 

r_exists = True
s_count = 0

while r_exists == True:

    r_exists = False

    i = N - 1

    while i >= 1:

        if A[i] < A[i - 1]:
            
            A[i], A[i - 1] = A[i - 1], A[i]

            s_count += 1

            r_exists = True
        
        i -= 1

s = ''

for x in A:

    s = s + str(x) + ' '

print(s.rstrip())
print(s_count)

