#include<stdio.h>

void trace(int array[],int N){
    int i;
    for(i=0; i<N; i++){
        if(i>0) printf(" ");
        printf("%d", array[i]);
    }
    printf("\n");
}

void insertionSort(int array[], int N){
    int j, i, v;
    for(i=1; i<N; i++){
        v = array[i];
        j = i - 1;
        while(j>=0 && array[j]>v){
            array[j + 1] = array[j];
            j--;
        }
        array[j+1]=v;
        trace(array,N);
    }
}

int main(){

    int i,N,j;
    int array[100]={};
    scanf("%d", &N);
    for(i=0; i <= N-1; i++) scanf("%d", &array[i]);

    trace(array,N);
    insertionSort(array,N);

    return 0;
}
