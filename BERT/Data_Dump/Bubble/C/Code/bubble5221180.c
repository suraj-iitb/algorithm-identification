#include <stdio.h>

int main() {

    int i, j, n;
    int arr[100];
    int count = 0;
    int temp;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf(" %d", &arr[i]);
    }

    for(i=0; i < n; i++) {
        for(j=1; j < n; j++){
            if (arr[j] < arr[j-1]) {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;   
                count ++;
            }

        }
    }

    /*Printing */
    for(i=0; i < n; i++) {
        if(i >= 1 ) printf(" ");
            printf("%d", arr[i]);
        
    }
    printf("\n");
    printf("%d\n", count);
    return 0;
}
