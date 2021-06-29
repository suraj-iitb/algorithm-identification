#include<stdio.h>
void bubbleSort(int*, int);

int main(){
    
    int S[100];
    int i, j, s, t;
    
    scanf("%d",&s);
    for(i=0 ; i<s ; i++){
        scanf("%d",&S[i]);
    }
    
    bubbleSort(S, s);
    
    return 0;
}

void bubbleSort(int *A,int b){
    int i,j;
    int flag = 1,cont=0;
    
    while(flag){
        flag = 0;
        for(i=b-1 ; i>=1 ; i--){
            if(A[i]<A[i-1]){
                j = A[i];
                A[i] = A[i-1];
                A[i-1] = j;
                flag = 1;
                cont++;
            }
        }
    }
    
    for(i=0 ; i<b ; i++){
        if(i==b-1){
            printf("%d\n", A[i]);
        }else{
            printf("%d ", A[i]);
        }
    }
    printf("%d\n",cont);
}
