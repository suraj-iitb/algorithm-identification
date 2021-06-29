#include <stdio.h>
int main() {
	int key,j,k,N;
   scanf("%d",&N);
   int A[N];
	for(int i=0;i<N;i++)
{	
	scanf("%d",&A[i]);
	}
   	for(int i=0;i<N;i++){
		key=A[i];
		j=i-1;
		while (j>=0&&A[j]>key){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=key;
		 for(k=0; k<N; k++){
            printf("%d",A[k]);
            if(k<N-1) printf(" ");
        }
        printf("\n");
	}
return 0;
}
