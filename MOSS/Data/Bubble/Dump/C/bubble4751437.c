#include <stdio.h>
void swap(int *a,int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}
int sort(int A[],int N){
	int i,j,sw;
	sw = 0;
	unsigned short flag = 1;
	for(i = 0; flag;i++){
		flag = 0;
		for(j = N-1; j >= i+1;j--){
			if(A[j] < A[j-1]){
				swap(&A[j],&A[j-1]);
				flag = 1;
				sw++;
			}
		}
	}
	return sw;
}
int main(void){
	int R[100],r,i,sw;
	scanf("%d",&r);
	for(i = 0; i < r; i++) scanf("%d",&R[i]);
	sw = sort(R,r);
	for(i = 0; i < r; i++){
		if(i) printf(" ");
		printf("%d",R[i]);
	}
	printf("\n%d\n",sw);
	return 0;
}
