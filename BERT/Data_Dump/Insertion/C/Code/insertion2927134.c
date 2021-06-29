#include<stdio.h>
int main() {

    int n, j, key;
    int arr[1000+5];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
    for ( int i = 0; i < n; i++ ) {
        j = i - 1;
        key = arr[i];

        while( j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;

        for(int k = 0; k < n; k++) {
            if( k > 0 ) printf(" ");
            printf("%d", arr[k]);
        }
        printf("\n");
    }
    return 0;
}


