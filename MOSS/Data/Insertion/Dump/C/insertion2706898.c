#include <stdio.h>
#define MAXSIZE 100

void insertionSort(int a[],int size);
void printArray(int a[],int size);

int main(void){
    int i,size,array[MAXSIZE];
    scanf("%d",&size);

    for(i=0;i<size;i++){
        scanf("%d",&array[i]);
    }

    insertionSort(array,size);

    return 0;
}

void insertionSort(int a[],int size){
    int i,j,temp;
    for(i=0;i<size;i++){
        temp=a[i];
        for(j=i;j>0&&a[j-1]>temp;j--){
            a[j]=a[j-1];
        }
        a[j]=temp;
     	printArray(a,size);
    }
}

void printArray(int a[],int size){
    int i;
    printf("%d",a[0]);
    for(i=1;i<size;i++){
    printf(" %d",a[i]);
    }
    printf("\n");
}




