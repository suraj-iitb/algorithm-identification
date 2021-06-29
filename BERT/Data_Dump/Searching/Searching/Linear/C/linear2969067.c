#include <stdio.h>
#include <stdlib.h>

int linSearch(int,int[],int);

int main(int argc, char** argv) {
    int size1;
    scanf("%d\n", &size1);
    int array1[size1];
    for(int i = 0; i < size1; i++)
        scanf("%d", &array1[i]);
    
    int size2;
    scanf("%d\n", &size2);
    int array2[size2];
    for(int i = 0; i < size2; i++)
        scanf("%d", &array2[i]);
    
    int searched[size1];
    for(int i = 0; i < size1; i++)
        searched[i] = 0;
    int count = 0;
    int temp;
    for(int i = 0; i < size2; i++){
        temp = linSearch(size1,array1,array2[i]);
        if(temp >= 0 && temp < size1)
            searched[temp]++;
    }
    
    for(int i = 0; i < size1; i++)
        if(searched[i])
            count++;
    
    printf("%d\n", count);
    return (EXIT_SUCCESS);
}

int linSearch(int size, int array[size], int searchVal){
    int i = 0;
    while(array[i] != searchVal && i < size)
        i++;
    if(i == size)
        return -1;
    return i;
}

