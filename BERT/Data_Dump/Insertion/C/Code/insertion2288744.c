#include <stdio.h>

int main(void){
    int num;
    int A[100];
	int i, j, k;
	int V;

    scanf("%d", &num);

    for(i=0; i<num; i++){
        scanf("%d", &A[i]);
    }

    for(i=1; i<=num; i++){
        for(k=0; k<num; k++){
			if(k==num-1){
				printf("%d", A[k]);
			}else{
				printf("%d ", A[k]);
			}
		}
		printf("\n");
        V = A[i];
        j = i-1;

        while(A[j] > V  && j >= 0){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = V;
    }

	return 0;
}
