#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int *a,int n);
void insertSort(int *a,int n);

int main(void) {
    int i,n;
    int a[100];
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printArray(a,n);
    insertSort(a,n);
    
    return 0;
}

void insertSort(int *a,int n){
    int i,j,v;
    for(i=1;i<n;i++){
        v = *(a+i);
        j = i - 1;
        while(j>=0 && *(a+j)>v){
            *(a+j+1) = *(a+j);
            j--;
        }
        *(a+j+1) = v;
        printArray(a,n);
    }
}

void printArray(int *a,int n){
    int i;
    for(i=0;i<n-1;i++){
        printf("%d ",*(a+i));
    }
    printf("%d\n",*(a+n-1));
}
