#include<stdio.h>
#include<stdlib.h>
 
main(){
    int *A,key,i,j,tmp,count =0;
    scanf("%d",&key);
    A = (int *)malloc(sizeof(int) * key);
    if(A == NULL){
    exit(0);
    }
     
    for(i=0;i<key;i++){
        A[i] = 0;
    }
    for(i=0;i<key;i++){
    scanf("%d",&A[i]);
    }
    for(i =0; i<=key-1;i++){
        for(j=key-1;j >i;j--){
            if(A[j] < A[j-1]){
        count++;
                tmp=A[j];
                A[j]=A[j-1];
                A[j-1]=tmp;
            }
        }
    }
    for(i=0;i<key;i++){
        if(i!=key-1){
        printf("%d ",A[i]);
        }else{
        printf("%d",A[i]);
        printf("\n");
        }
    }
    printf("%d\n",count);
     
    free(A);
     
    return 0;
}
