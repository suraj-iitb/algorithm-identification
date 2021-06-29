#include<stdio.h>
int n, i, j, min, s, COUNT=0, A[100];

main(){
    scanf("%d",&n);
    
    for(i=0; i<n; i++){
        scanf("%d",&A[i]);
    }
    
    for(i=0; i<n; i++){
        min = i;
        for(j=i+1; j<n; j++){
            if(A[j]<A[min]){
              min = j;
            }
        }
        if(i != min){
            s = A[i];
            A[i] = A[min];
            A[min] = s;
            COUNT += 1;
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
    printf("%d\n", COUNT);
}
