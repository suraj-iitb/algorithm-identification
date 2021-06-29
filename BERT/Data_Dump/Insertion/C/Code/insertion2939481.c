#include <stdio.h>
#include <stdlib.h>

#define LIMIT 100

void printArray(int[],int);

int main(int argc, char** argv) {
    int count;
    int error = 0;
    
    int checkScan = scanf("%d", &count);
    if(checkScan != 1)
        return (EXIT_FAILURE);
    
    const int arraySize = count;
    int array[arraySize];
    
    if(count > LIMIT || count < 1)
        return(EXIT_FAILURE);
    
    int chkScan;
    for(int i = 0; i < count; i++){
        chkScan = scanf("%d", &array[i]);
        if(chkScan != 1)
            return(EXIT_FAILURE);
    }
    
    printArray(array, count);
        
    int temp, j;
    for(int i = 1; i < count; i++){
        temp = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > temp)
            array[j+1] = array[j--];
        array[j+1] = temp;
        printArray(array, count);
    }
    
    return (EXIT_SUCCESS);
}

void printArray(int array[], int count){
    for(int i = 0; i < count; i++){
        if(i != count - 1)
            printf("%d ", array[i]);
        else if(i == count - 1)
            printf("%d", array[i]);
    }
    printf("\n");
}

