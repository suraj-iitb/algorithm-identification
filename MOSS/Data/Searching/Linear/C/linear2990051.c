#include <stdlib.h>
#include <stdio.h>

            
int main(int argc, char** argv) {
    int n1, n2;
    scanf("%d", &n1);
    int A[n1+1];
    for(int i=0; i<n1; i++){
        scanf("%d", &A[i]);
    }
    
    scanf("%d", &n2);
    int B[n2];
    for(int i=0; i<n2; i++){
        scanf("%d", &B[i]);
    }
    
    int counter = 0;
    for(int i=0; i<n2; i++){
        A[n1+1] = B[i]; 
        for(int j=0; j<n1; j++)
            if(A[j]==A[n1+1]){ 
                counter++;
                break;
            }
    }
    printf("%d\n", counter);
    return 0;
}
