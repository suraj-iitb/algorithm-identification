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
    int temp;
    for(int i = 0; i < Num - 1; i++){
       for(int j = 0; j <  Num - i - 1 ; j++){
          if(A[j] > A[j+1]){
              swap++;
              temp = A[j+1];
              A[j+1] = A[j];
              A[j] = temp;
              
          } 
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

