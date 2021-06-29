#include <stdio.h>
int main(void){
	int N,i,j,num[101]={0},temp,cnt=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&num[i]);
	}
	for(i=0;i<N;i++){
		for(j=N-1;j>i;j--){
			if(num[j]<num[j-1]){
				temp=num[j];
				num[j]=num[j-1];
				num[j-1]=temp;
				cnt++;
			}
		}
	}
	for(i=0;i<N;i++){
		printf("%d",num[i]);
		if(i!=N-1) printf(" ");
	}
	printf("\n%d\n",cnt);
	return 0;
}
