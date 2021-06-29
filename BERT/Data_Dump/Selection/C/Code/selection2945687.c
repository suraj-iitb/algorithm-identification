#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int size;
    scanf("%d\n", &size);
    if(size < 1 || size > 100)
        return (EXIT_FAILURE);
    int array[size];
    
    for(int i = 0; i < size; i++)
        scanf("%d", &array[i]);
    
    int minLoc, temp;
    int count = 0;
    for(int i = 0; i < size; i++){
        minLoc = i;
        for(int j = i; j < size; j++)
            if(array[j] < array[minLoc])
                minLoc = j;
        if(minLoc != i)
            count++;
        temp = array[i];
        array[i] = array[minLoc];
        array[minLoc] = temp;
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


