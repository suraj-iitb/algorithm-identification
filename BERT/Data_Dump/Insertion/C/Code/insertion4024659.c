#include<stdio.h>
#define N 100

int main(){
    int i,j,k,v,A[N];

    scanf("%d",&i);

    for(j = 0;j < i;j++){
        scanf("%d",&A[j]);
        printf("%d",A[j]);
        if(j == (i - 1)) break;
        printf(" ");
    } printf("\n");

    for(j = 1;j < i;j++){
        v = A[j];
        k = j - 1;
        while(k >= 0 && A[k] > v){
            A[k+1] = A[k];
            k--;
            A[k+1] = v;
        }
        for(k = 0;k < i;k++){
            printf("%d",A[k]);
            if(k == (i - 1)) break;
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
