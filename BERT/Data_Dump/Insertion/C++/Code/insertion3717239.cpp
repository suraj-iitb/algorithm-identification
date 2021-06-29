#include<stdio.h>

void trace(int a[], int n){
    for(int i=0;i<n;i++){
        if(i>0)printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

void insertionSort(int a[], int n){
    for(int i=1;i<n;i++){    // current immigrant cadidate 
        int now=a[i];
        int j=i-1;
        while(j>=0 &&a[j]>now){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=now;
        trace(a,n);
    }
}

int main(){

    int n, i, j;

    int a[100];

    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    trace(a,n);
    insertionSort(a,n);

    return 0;
}

