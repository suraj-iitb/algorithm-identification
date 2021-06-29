#include<stdio.h>
void insertionSort(int*,int); 
int main(){
    int array[100];
    int a,b,i,j;
    scanf("%d",&a);
    for(i=0;i<a;i++){
        scanf("%d",&array[i]);
    }
    insertionSort(array,a);
}

//algorithm
void insertionSort(int* a,int b){
    int i,j,k,v;
    for(i=0;i<b;i++){
        v=a[i];
        j=i-1;
        while(j>=0 && a[j]>v){
            a[j+1] = a[j];
            j--;
            a[j+1] = v;
        }
        for(k=0;k<b;k++){
            if(k==b-1){
                printf("%d",a[k]);
            }
            else{
            printf("%d ",a[k]);
            }
        }
        printf("\n");
    }
}

