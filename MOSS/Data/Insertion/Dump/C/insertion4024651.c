#include <stdio.h>
int main(){
    int sizu, v;
    int i, j, k;

    scanf("%d",&sizu);
    int A[sizu];

    for(j = 0; j < sizu; j++){
        scanf("%d",&A[j]);
    }

    for(j = 1; j < sizu; j++){
        v = A[j];
        i = j - 1;

        for(k = 0; k < sizu; k++ ){
            if(k+1 == sizu){
                printf("%d\n",A[k]);
            }else{
                printf("%d ",A[k]);
            }
        }
        
        while( i >= 0 && (A[i] > v)){
            A[i+1] = A[i];
            i = i - 1;
        }
	    A[i+1] = v;
    }

    for(k = 0; k < sizu; k++ ){
        if(k+1 == sizu){
            printf("%d\n",A[k]);
        }else{
            printf("%d ",A[k]);
        }
    }

    return 0;
}

