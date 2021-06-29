#include<stdio.h>
int main(){
	int number[100];
	int N;
	int i,j,k,tmp,count;

	scanf("%d",&N);

	for(count = 0;count < N; count++){
		scanf("%d",&number[count]);
	}
	//sort ??¨???
	for(j=0;j<N;j++){
		
		for(i=0;i<N;i++){
			printf("%d",number[i]);
			if(i == N-1){
				printf("\n");
			}
			else{
				printf(" ");
			}
		}
		
		for(k=j+1;k>0;k--){
			if(number[k] - number[k-1]<0){
				tmp = number[k];
				number[k] = number[k-1];
				number[k-1] = tmp;
			}
		}
	}
}
