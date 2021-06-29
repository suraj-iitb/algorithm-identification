//#include <iostream>
#include <stdio.h>

void display(int a[],int n){
    int i;
    for (i = 0; i < n; ++i) {
        if (i>0)
            printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}

void insertionSort(int a[],int n){
    int v,i,j;
    for (i = 1; i < n; ++i) {
        v=a[i];
        for (j = i-1; j >=0&&a[j]>v ; --j) {
            a[j+1]=a[j];
        }
        a[j+1]=v;

        display(a,n);
    }
}


int main() {
    int n,i;
    int a[150];
    scanf("%d",&n);
    for (i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }

    display(a,n);
    insertionSort(a,n);

    return 0;
}
