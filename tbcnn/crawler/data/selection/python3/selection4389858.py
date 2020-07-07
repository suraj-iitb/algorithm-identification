N=int(input())
S=list(map(int,input().split()))

counter=0
for i in range(0,N-1):
    min_,min_index=min(S[i:]),S[i:].index(min(S[i:]))+i
    first_element,first_element_index=S[i],i
    
    if min_index!=first_element_index:
        counter+=1
        S[first_element_index],S[min_index]=S[min_index],S[first_element_index]
        
print(*S)
print(counter)
