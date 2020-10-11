#include <stdio.h>

int main( void ){
	int i, j, n, m, minj, count;  //mは交換に使う変数
	scanf("%d", &n);
	int A[n];
	for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
	
	count = 0;
	for(i = 0; i < n; i++){
		minj = i;
		for(j = i; j < n; j++){
			if(A[j] < A[minj]){
				minj = j;
			}
		}
		if(i != minj){
			count++;
		}
		m = A[i];
		A[i] = A[minj];
		A[minj] = m;		
	}
	
	for(i = 0; i < n; i++){
        printf("%d", A[i]);
        if(i < n - 1){
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n", count);
	
	return 0;
}

