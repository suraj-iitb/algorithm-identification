#include <stdio.h>

#define N 10000

int count = 0, numA, A[N];

void search(int);

int main () {
    int B[N], numB, i;

    scanf("%d",&numA);
    
    for(i = 0; i < numA; i++){
        scanf("%d",&A[i]);
    }

    scanf("%d",&numB);
    
    for(i = 0; i < numB; i++){
        scanf("%d",&B[i]);
    }

    for(i = 0; i < numB; i++){
        search(B[i]);
    }

    printf("%d\n", count);

    return 0;
}

void search(int num){
    int i;
    for(i = 0; i < numA; i++){
        if(num == A[i]) {
            count++;
            break;
        }
    }
}
