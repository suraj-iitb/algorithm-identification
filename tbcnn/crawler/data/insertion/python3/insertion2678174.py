n=int(input())
s=input().split(' ')

print(' '.join(s))

for i in range(1,n):
	v=int(s[i])
	j=i-1
	while j>=0 and int(s[j])>v:
		s[j+1]=s[j]
		j-=1
	s[j+1]=str(v)
	print(' '.join(s))
