#include<stdio.h>

int n,A[1000];

void printSort(int A[]){

	printf("%d",A[0]);
	for(int i = 1; i < n; i++){
		printf(" %d",A[i]);
	}
	printf("\n");
}


void insertionSort(){

	int v;

	for(int i = 1; i < n; i++){

		v = A[i];
		
		for(int j = i-1; j >= 0; j--){

		if(A[j] > v){
			A[j+1] = A[j];
			A[j] = v;
		}
		else	break;

		}

		printSort(A);

	}

}


int main(){

	scanf("%d",&n);

	for(int i = 0; i < n; i++){
		scanf("%d",&A[i]);
                            //printf("%d", A[i]);
	}
              printSort(A);
	insertionSort();

	return 0;
}
