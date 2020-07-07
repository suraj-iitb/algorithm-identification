N=int(input())
L=list(map(int,input().split()))
L_temp=L

A_N=100010
counter=[0]*A_N

for l in L_temp:
    counter[l]+=1
    
for c_idx in range(1,len(counter)):
    counter[c_idx]+=counter[c_idx-1]
# print(counter)
    
L_sort=[0]*len(L_temp)

for l in L_temp[::-1]:
    L_sort[counter[l]-1]=l
    # print(l,counter[l],L_sort)
    counter[l] -= 1
    
print(' '.join(map(str,L_sort)))
