#include<stdio.h>


void swap(int *A, int index1, int index2, int *count){
    (*count)++;
    int temp = A[index1];
    A[index1] = A[index2];
    A[index2] = temp;

}

void printArray(int *A, int sizeA){
    /*int sizeA = sizeof(A)/sizeof(A[0]);*/
    for (int i=0; i<sizeA; i++){
        printf("%d", A[i]);
        if(i<sizeA-1){
            printf(" ");
        }
    }
};


int main()
{   
    int count = 0;
    int size;
    scanf("%d", &size); 
    /*printf("You're array is of size %d, now input the array\n", size);*/
    int A[size];
    for (int i=0; i<size; i++){
        scanf("%d", &A[i]);
    }


    /* BUBBLE SORT */

    for (int i=0; i<size-1; i++){
        for (int j = size-1; j>0; j--) {
            if (A[j] < A[j-1]){
                swap(A,j,j-1, &count);
            }
        }
        
    };
    printArray(A,size);
    printf("\n%d\n", count);
    return 0;
}

