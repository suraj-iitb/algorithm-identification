#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define MOD 1000000007
#define MAXE9 1000000000

int i, j, k, l = 0;
    int N, v;
    int A[1001];

void InsSRT(void){
    for(i=1;i<N;i++){
        v = A[i];
        j = i-1;
        while(j>=0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
                for(k=0;k<N;k++){
            printf("%d", A[k]);
            if(k!=N-1) printf(" ");
        }
        printf("\n");
    }
}

int main(){
    scanf("%d", &N);
    for(i=0;i<N;i++){
        scanf("%d", &A[i]);
    }
    for(i=0;i<N;i++){
        printf("%d", A[i]);
        if(i!=N-1) printf(" ");
    }
    printf("\n");
    InsSRT();
    
    return 0;
}
