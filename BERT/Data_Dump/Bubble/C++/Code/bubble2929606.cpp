#include<stdio.h>

int ans;

void swap_(int *f, int *b) {
int temp;
temp = *f;
*f = *b;
*b = temp;
ans++;
}

void bSort(int arr[], int n) {

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
		if ( arr[j] > arr[j+1])
	     swap_(&arr[j], &arr[j+1]);
        }
    }
    return;
}


int main() {

    int n;
    int arr[100+5];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    bSort(arr, n);
    for(int i = 0; i < n ; i++) {
        if( i > 0 ) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n%d\n", ans);
    return 0;
}

