#include<stdio.h>
#include<stdlib.h>


void trace(int a[],int n){
    int i;
    for(i = 0;i<n;i++){
        if(i>0)printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}

void InsertionSort(int a[],int n){
    int i,j;
    int v;
    for(i = 1;i<n;i++){
        v = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > v){
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] = v;
        trace(a,n);
    }
}

int main(void){
    int a[100];
    int i;
    int n;
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    trace(a,n);
    InsertionSort(a,n);
    return 0;
}
