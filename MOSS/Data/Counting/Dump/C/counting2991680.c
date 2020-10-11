#include <stdio.h>
#include <stdlib.h>

int counting_sort(int,int[],int[],int);
void printArray(int,int[]);
int max(int,int);

int main(int argc, char** argv) {
    int size;
    scanf("%d\n", &size);
    int array[size];
    for(int i = 0; i < size; i++)
        scanf("%d", &array[i]);
    int sort[size];
    
    int maxVal = -1;
    for(int i = 0; i < size; i++)
        maxVal = max(maxVal,array[i]);
    
    counting_sort(size,array,sort,maxVal);
    printArray(size,sort);
    return (EXIT_SUCCESS);
}

int counting_sort(int size, int orig[size], int sorted[size], int maxVal){
    int countSize = maxVal+1;
    int count[countSize];
    for(int i = 0; i < countSize; i++)
        count[i] = 0;
    for(int j = 0; j < size; j++)
        count[orig[j]] = count[orig[j]]+1;
    for(int i = 1; i < countSize; i++)
        count[i] = count[i] + count[i-1];
    for(int j = 0; j < countSize; j++)
        count[j]--;
    for(int j = size-1; j >= 0; j--)
        sorted[count[orig[j]]--] = orig[j];
}

void printArray(int size, int a[size]){
    for(int i = 0; i < size; i++){
        if(i != size - 1)
            printf("%d ", a[i]);
        else printf("%d\n", a[i]);
    }
}

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}

