#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int value;
    int done;
}data;
/*
 * 
 */

int main(int argc, char** argv) {

    
    int n, track;
    scanf("%d",&n);
    int *A =(int*)malloc(n *sizeof(int));
    for(int a = 0; a < n; a++){
 
            scanf("%d",&A[a]);
    }

    int m;
    scanf("%d",&m);
    data *B = (data*)malloc(n * sizeof(data));
    for(int a = 0; a < m; a++){
        scanf("%d",&B[a].value);
        B[a].done = 0;
    }
    
    for(int a = 0; a < n; a++){
        for(int b = 0; b < m; b++){
            if((A[a] == B[b].value) && (B[b].done == 0)){
            track++;
            B[b].done=1;
            }
        }
    }
    
    free(A);
    free(B);
    printf("%d",track);
    printf("\n");
    
    return (0);
}

