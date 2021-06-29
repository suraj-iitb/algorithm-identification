#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int size;
    scanf("%d\n", &size);
    if(size < 1 || size > 100)
        return (EXIT_FAILURE);
    int array[size];
    
    for(int i = 0; i < size; i++){
        scanf("%d", &array[i]);
    }
    
    int count = 0;
    int temp;
    for(int i = 0; i < size; i++){
        for(int j = size - 1; j > i; j--){
            if(array[j] < array[j - 1]){
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
                count++;
            }
        }
    }
    for(int i = 0; i < size; i++){
        if(i == size - 1)
            printf("%d\n",array[i]);
        else
            printf("%d ", array[i]);
    }
    printf("%d\n",count);
    return (EXIT_SUCCESS);
}


