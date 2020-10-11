#include <stdio.h>

int main(void){

    int arr[101];
    int key;
    int i, j, k, n;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }



    // sore start
    for (i = 1; i<=n; i++) {
        key = arr[i];
        j = i - 1;

        // print
        for(k=0; k<n; k++){
            if(k == n - 1) printf("%d", arr[k]);
            else printf("%d ", arr[k]);
        }
        printf("\n");

        while ((j>=0) && (arr[j] > key)) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;


    }


    return 0;
}
