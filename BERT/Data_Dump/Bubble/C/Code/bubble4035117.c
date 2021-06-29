#include <stdio.h>
#include <stdlib.h>
int main(){
        int n, i, j, num_s, buffer;
        int *array;

        scanf("%d", &n);

        array = (int *)malloc(n * sizeof(int));

        for(i = 0 ; i < n; i++){
                scanf("%d", &array[i]);
        }

        for(j = 0 ; j < n ; j++){
                for(i = n - 1 ; i > j ; i--){
                        if(array[i] < array[i - 1]){
                                buffer = array[i];
                                array[i] = array[i - 1];
                                array[i - 1] = buffer;
                                num_s++;
                        }
                }
        }

        for(i = 0 ; i < n ; i++){
                printf("%d", array[i]);
                if(i + 1 != n)printf(" ");
        }
        printf("\n");

        printf("%d\n", num_s);

        return 0;
}

