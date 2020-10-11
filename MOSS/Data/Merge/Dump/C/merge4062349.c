#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define INFTY (pow(10,9)+1);

int count=0;
void merge(int x[],int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    int *array1=malloc(sizeof(int)*n1+1);
    int *array2=malloc(sizeof(int)*n2+1);

    for(int i=0;i<n1;i++){
        array1[i]=x[left+i];
    }
    for(int j=0;j<n2;j++){
        array2[j]=x[mid+j];
    }
    array1[n1]=INFTY;
    array2[n2]=INFTY;

    for(int i2=0,j2=0,k=left;k<right;k++){
        if(array1[i2]<=array2[j2]){
            x[k]=array1[i2];
            i2=i2+1;
        }
        else{
            x[k]=array2[j2];
            j2=j2+1;
        }
        count++;
    }
    free(array1);
    free(array2);
}

void mergesort(int x[],int left,int right){
    int mid;
    if(left+1<right){
        mid=(left+right)/2;
        mergesort(x,left,mid);
        mergesort(x,mid,right);
        merge(x,left,mid,right);
    }
}

int main(){
    int n;
    int *array;

    scanf("%d",&n);
    array=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    mergesort(array,0,n);

    for(int j=0;j<n-1;j++){
        printf("%d ",array[j]);
    }
    printf("%d\n%d\n",array[n-1],count);

    free(array);

    return 0;

}

