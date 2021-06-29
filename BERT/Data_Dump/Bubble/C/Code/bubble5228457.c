#include<stdio.h>
int i, n, b, flag=1, COUNT=0, A[100];

main(){
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    
    while(flag){
        flag = 0;
        for(i=n-1; i>0; i--){
            if(A[i-1]>A[i]){
                b =A[i-1];
                A[i-1] = A[i];
                A[i] = b;
                COUNT += 1;
                flag = 1;
            }
        }
    }
    
    for(i=0; i<n; i++){
        printf("%d",A[i]);
        if(i == n-1){
            printf("\n");
        }else{
            printf(" ");
        }
    }
    
    printf("%d\n",COUNT);
}
