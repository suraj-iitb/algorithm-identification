#include<stdio.h>
#include<stdlib.h>

void insertionSort(int*arr, int n);

int main(){
    int i,j,n;
    scanf("%d",&n);
    int *arr;
    arr = malloc(n*sizeof(int));
    for (i=0;i<n;i++){
        scanf("%d",arr+i);
        //printf("%d",arr[i]);
    }
    insertionSort(arr,n);
    return 0;
}

void insertionSort(int*arr, int n){
    int i,j,k,v;
    for (i=0;i<n;i++){
        v = *(arr+i);
        j = i-1;
        while (j>=0 && *(arr+j)>v){
            arr[j+1] = arr[j];
            j--;
        }
        *(arr+j+1) = v;
        //printf("why?");
        for (k=0;k<n;k++){
            if (k==(n-1)) printf("%d\n",arr[k]);
            else printf("%d ",arr[k]);
    }

    }
    return;
}
