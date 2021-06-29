#include <stdio.h>
#include<string.h>
#include<stdlib.h>

void insertionSort(char *A,int N);

int main(void)
{
    char A[4 * 1000 + 99] = {};
    int N;
    
    scanf("%d\n",&N);
    fgets(A, 4 * 1000 + 99, stdin);
    insertionSort(A, N);

	return 0;
}

void insertionSort(char *B,int N)
{
    int A[100];
    int i = 0;
    char *p;
    int v = 0;
    int j = 0;
    int k;
    
    p = B;
    
    p = strtok(p, " ");
    
    while(p != NULL){
        A[i] = atoi(p);
        p = strtok(NULL, " ");
        i++;
    }
    
    for(i = 1; i < N; i++){
        v = A[i];
        j = i - 1;
        
        for(k = 0; k < N; k++){
            printf("%d",A[k]);
            if(k != N-1){
                printf(" ");
            }
        }
        printf("\n");
        
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
            A[j+1] = v;
        }
    }
    
    for(k = 0; k < N; k++){
        printf("%d",A[k]);
        if(k != N-1){
            printf(" ");
        }
    }
    printf("\n");
    
}
