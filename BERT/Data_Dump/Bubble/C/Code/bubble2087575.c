#include<stdio.h>
int main(){
	int number[100];
	int N;
	int j,k,tmp,count;
	int i = 0;

	scanf("%d",&N);

	for(count = 0;count < N; count++){
		scanf("%d",&number[count]);
	}
	

	int flag= 0;
	for(flag = 0;flag < N-1;flag++)
	for(i = 0; i+1 <N-flag;i++){
		if(number[i] > number[i+1]){
			tmp = number[i];
			number[i] = number[i+1];
			number[i+1] = tmp;
			j++;
		}
	}
	for(k=0;k<N;k++){
		printf("%d",number[k]);
		if(k != N-1){
			printf(" ");
		}
		else{
			printf("\n%d\n",j);
		}
	}
	return 0;

}
