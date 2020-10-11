
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    int Num;
    scanf("%d",&Num);
    int A[100+5]; 
    for(int a = 0; a < Num; a++){
        
        scanf("%d",&A[a]);
    }

    int swap = 0;
    int temp1, temp;
    int min, k, exe;
    
    for(int i = 0; i < Num - 1; i++){
        min = i;
        exe = i;
       for(int j = i + 1; j <  Num; j++){
              if(A[exe] > A[j]){
                  exe = j;
              }
       }
        if(A[i] > A[exe]){
           temp = A[i];
           A[i] = A[exe];
           A[exe] = temp;
           swap++;
        }
    }
    for(int a = 0; a < Num; a++){
        
            printf("%d",A[a]);
            if(a < Num - 1){
                printf(" ");
            } 
    }
    
    printf("\n%d\n",swap);
    return (0);
}
