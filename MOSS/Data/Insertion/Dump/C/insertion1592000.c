#include <stdio.h>


void print_array(int a[], int len);
void insertionSort(int a[], int len);

void insertionSort(int a[], int len) {
    int i, v, j;
    for(i = 1; i < len; i++ ) {
        print_array(a,len);
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
}

void print_array(int a[], int len) {
    int i;
    printf("%d",a[0]);
    for(i = 1; i < len; i++ ) {
        printf(" %d",a[i]);
    }
    puts("");
}

int main(void) {
    int array[1000];
    int v, i, j, tmp, length;
    scanf("%d",&length);
    for(i = 0; i < length; i++ ) {
        scanf("%d",&array[i]);
    }
    insertionSort(array,length);
    print_array(array, length);
    v = array[i];
    j = i;
    return 0;
}
