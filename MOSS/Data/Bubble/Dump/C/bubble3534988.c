#include<stdio.h>
int main(){
	int flag=1;
	int A[101];
	int n,i=0,j,tmp,cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&A[i]);
	i=0;
	while(flag){
		flag=0;
		for(j=n-1;j>i;j--){
			if(A[j]<A[j-1]){
				cnt++;
				tmp=A[j];
				A[j]=A[j-1];
				A[j-1]=tmp;
				flag=1;
			}
		}
		i++;
	}
	for(i=0;i<n-1;i++)printf("%d ",A[i]);
	printf("%d\n",A[i]);
	printf("%d\n",cnt);
	return 0;
}
