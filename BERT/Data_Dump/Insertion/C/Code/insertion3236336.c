#include <stdio.h>

int main(void)
{
    int j,v,N;
    int A[100];
    
    scanf("%d\n",&N);

    for (int i=0; i<N; i++) {
        scanf("%d",&A[i]);
    }
    for (int q=0; q < N-1; q++) {
            printf("%d ",A[q]);
        }
    printf("%d\n",A[N-1]);
    
    for (int i = 1; i < N; i++) {
		v = A[i];
		j = i - 1;
		
		while (j >= 0 && A[j] > v) {
		    A[j+1] = A[j];
		    j--;
		}
		A[j+1] = v;
		
		for (int k=0; k < N-1; k++) {
            printf("%d ",A[k]);
        }
        printf("%d\n",A[N-1]);
    }
    return 0;
}
