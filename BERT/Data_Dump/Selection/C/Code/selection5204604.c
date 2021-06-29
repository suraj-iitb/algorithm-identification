#include<stdio.h>


void swap(int *A, int index1, int index2, int *count){

    if (index1 != index2){
    (*count)++;
    int temp = A[index1];
    A[index1] = A[index2];
    A[index2] = temp;
    };

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


    /* SELECTION SORT */

    for (int i=0; i<size-1; i++){
        int mini = i;
        for (int j = i; j<size; j++) {
            if (A[j] < A[mini]){
                mini = j;
            }
            
        }
        swap(A,mini,i, &count);
        
    };
    printArray(A,size);
    printf("\n%d\n", count);
    return 0;
}
