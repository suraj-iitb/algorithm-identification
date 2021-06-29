#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct card{
	char design;
	unsigned int num;
	int count;
}card;

int partition(card *A,int p,int r){
	unsigned int x = A[r].num;
	int i = p-1;
	int j = 0;
	card temp;
	for(j = p;j < r;j++){
		if(A[j].num <= x){
			i = i+1;
			memcpy(&temp,&A[i],sizeof(card));
			memcpy(&A[i],&A[j],sizeof(card));
			memcpy(&A[j],&temp,sizeof(card));
			
		}
	}
	memcpy(&temp,&A[i+1],sizeof(card));
	memcpy(&A[i+1],&A[r],sizeof(card));
	memcpy(&A[r],&temp,sizeof(card));
	
	return i+1;
}

void quicksort(card *A,int p,int r){
	int q = 0;
	if(p < r){
		q = partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}

int main(int argc, char **argv){
	int n = 0;
	int i = 0;
	int r = 0;
	int flag = 0;
	char temp[3];
	scanf("%d",&n);

	card *A = malloc(sizeof(card) * n);

	for(i = 0;i < n;i++){
		scanf("%*c%c %d",&A[i].design, &A[i].num);
		A[i].count = i;
	}

	quicksort(A,0,n-1);
	for(i = 1;i < n;i++){
		if(A[i].num == A[i-1].num && A[i].count < A[i-1].count){
			flag = 1;
		}
	}

	if(flag == 1){
		printf("Not stable\n");
	}
	else{
		printf("Stable\n");
	}
	for(i = 0;i < n;i++){
		printf("%c %d\n",A[i].design, A[i].num);
	}
}

