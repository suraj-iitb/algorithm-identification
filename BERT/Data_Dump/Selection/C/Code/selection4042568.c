#include<stdio.h>
int main()
{
    int n,i,j,minj,tmp,count=0;
    int A[100];

    scanf("%d",&n);
    for(i = 0; i < n; ++i)
        scanf("%d",&A[i]);

        for(i = 0; i < n; ++i){
            minj = i;
            for(j = i; j < n; j++){
                if(A[j] < A[minj]){
                    minj = j;   
                }
            } 
             if(minj != i){ 
                tmp = A[i];
                A[i] = A[minj];
                A[minj] = tmp; 
                count++; 
             }     
        }
    for(i =0; i < n; ++i){
        printf("%d",A[i]);
        if(i < n-1)
        printf(" ");
    }
    printf("\n");
    printf("%d\n",count);
    return 0;
}
