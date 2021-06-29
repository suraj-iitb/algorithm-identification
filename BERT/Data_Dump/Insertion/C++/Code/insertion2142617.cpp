#include <stdio.h>
#include <iostream>

int main() {
    int arr[100], v;
    int n, i, j;
    
    //input
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    /* main processing */
    //sort
    for (i = 0; i < n; i++) {
        v = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > v) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = v;
        
        //output
        for (j = 0; j < n; j++) {
            if (j < n-1) {
                printf("%d ", arr[j]);
            }
            else {
                printf("%d\n", arr[j]);
            }
        }
    }
    
    return 0;
}
