#17D8101028I tou koutetsu  2019/10/3
#ID:tanghaozhe 
#python

n=int(input())
X=list(map(int,input().split()))
curX=[]
for index,i in enumerate(X):
	curX.append(i)
	for j in range(index,0,-1):
		# print(curX,"j=",j)
		if j>0 and curX[j]<curX[j-1]:
			tmp=curX[j-1]
			curX[j-1]=curX[j]
			curX[j]=tmp
	res=curX+X[index+1:]
	print(' '.join(str(e) for e in res))




