#include<stdio.h>
#include<stdlib.h>

int main(){
    int A[100];  
    int N;
    int i,j,mini,z;
    int count=0;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }

    for(i=0;i<N;i++){
        mini = i;
        for(j=i;j<N;j++){
            if(A[j]<A[mini]){
                mini = j;
            }
        }  
        if(mini!=i){
            z = A[i];
            A[i] = A[mini];
            A[mini] = z;
            count++;
        }
    }  
    for(i=0;i<N;i++){
        printf("%d",A[i]);
        if(i!=N-1){
                printf(" ");
            }
    }  
    printf("\n%d\n",count);
    return 0;    
}
