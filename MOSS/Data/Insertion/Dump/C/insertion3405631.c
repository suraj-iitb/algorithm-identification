#include<stdio.h>

void insertionSort(int a[1000], int N);

int main(void){
    int a[1000],N,i,j;
    scanf("%d",&N);
    
    for(i=0;i<N;i++){
        scanf("%d ",&a[i]);
    }

    insertionSort(a,N);

}

void insertionSort(int a[1000], int N){
    int i,j,k,v;

    printf("%d",a[0]);
    for(k=1;k<N;k++){
        printf(" %d",a[k]);
    }
    printf("\n");
 

    for(i=1;i<N;i++){
        v=a[i];
        j=i-1;
        while(j>=0 && a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;

        printf("%d",a[0]);
        for(k=1;k<N;k++){
            printf(" %d",a[k]);
        }
        printf("\n");
    }
        
}

