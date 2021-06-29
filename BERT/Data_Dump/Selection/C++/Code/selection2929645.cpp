#include<stdio.h>

int ans;

void swap_(int *f, int *b) {
    int temp;
    temp = *f;
    *f = *b;
    *b = temp;
}

void selectionSort(int arr[], int n) {
    int minIndex;
    bool flag = false;
    for(int i =0; i < n-1; i++) {
        minIndex = i;
        for(int j = i+1; j < n; j++) {
            if (arr[minIndex] > arr[j]) {
                minIndex = j;
                flag = true;
            }
        }
        if(flag) {
            ans++;
            flag = !flag;
        }
        swap_(&arr[minIndex], &arr[i]);
    }

}


int main() {

    int n;
    int arr[100+5];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    selectionSort(arr, n);
    for(int i = 0; i < n ; i++) {
        if( i > 0 ) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n%d\n", ans);
    return 0;
}

