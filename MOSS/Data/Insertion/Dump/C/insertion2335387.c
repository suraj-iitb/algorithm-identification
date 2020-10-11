#include<stdio.h>

int main()
{
	int n,key,i,j,k;
	int A[100];

	scanf("%d",&n);
	for( i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	for(j = 0;j < n;j++){
        key = A[j];
        i = j-1;
        for(i > 0;A[i] > key;i--){
            A[i+1] = A[i];
        }
        A[i+1] = key;
        for(k = 0;k < n;k++){
            printf("%d",A[k]);
            if(k < n-1){
                printf(" ");
            }else{
                printf("\n");
            }
        }
         
    }
return 0;
}
