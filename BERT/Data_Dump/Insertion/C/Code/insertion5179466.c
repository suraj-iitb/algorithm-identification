#include <stdio.h>

int main()
{
    int i, j, k, N, key;
    int arr[100]; /* 1<= N =<100 */

    /*reading the inputs N and arr[]*/
    scanf("%d", &N);
    for (i = 0; i < N; i++){
        scanf("%d", &arr[i]); 
    }
    
    /*Printing array */
    for (i = 0; i < N - 1; i++){
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[i]);

    /*Insertion Algorithm */
    for (i = 1; i < N; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        for (k = 0; k < N - 1; k++){
            printf("%d ", arr[k]);
        }
        printf("%d\n", arr[k]);
    }
    return 0;
}
