#include<stdio.h>
int main(){
	int flag=1;
	int A[101];
	int m,i=0,j,t,cnt=0;
	scanf("%d",&m);
	for(i=0;i<m;i++){
 		scanf("%d",&A[i]);
	}
	i=0;
	while(flag){
		flag=0;
		for(j=m-1;j>i;j--){
			if(A[j]<A[j-1]){
				cnt++;
				t=A[j];
				A[j]=A[j-1];
				A[j-1]=t;
				flag=1;
			}
		}
		i++;
	}
	for(i=0;i<m-1;i++){
		printf("%d ",A[i]);
	}
	printf("%d\n",A[i]);
	printf("%d\n",cnt);
	return 0;
}


