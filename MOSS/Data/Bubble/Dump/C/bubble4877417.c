#include <stdio.h>
#define ARR_LEN 255

int sum;

void bubbleSort (int arr[], int len) {
    int temp;
    int i, j;
    for (i=0; i<len-1; i++)
        for (j=0; j<len-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                sum++;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

}

int main () {
	int len,arr[ARR_LEN],i;
	scanf("%d",&len);

    for(i=0; i<len; i++){
    	scanf("%d", &arr[i]);
	}

    bubbleSort (arr, len);

    for (i=0; i<len; i++){
        printf ("%d", arr[i]);
        if (i != len - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    printf("%d\n", sum);

    return 0;
}
