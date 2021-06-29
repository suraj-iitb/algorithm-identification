#include <stdio.h>
int main(void){
	int N,num[101]={0},i,j,cnt=0,mini,temp;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&num[i]);
	}
	for(i=0;i<N;i++){
		mini=i;
		for(j=i;j<N;j++){
			if(num[j]<num[mini]){
				mini=j;
			}
		}
		if(num[i]>num[mini]){
			temp=num[i];
			num[i]=num[mini];
			num[mini]=temp;
			cnt++;
		}
	}
	for(i=0;i<N;i++){
		printf("%d",num[i]);
		if(i!=N-1) printf(" ");
	}
	printf("\n%d\n",cnt);
	return 0;
}
