#include<stdio.h>
int main(){
    int A[100];
    int N,i,sw;

    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }

    sw=selectionSort(A,N);
    for(i=0;i<N;i++){
        if(i>0){
            printf(" ");
        }
        printf("%d",A[i]);
    }
    printf("\n");
    printf("%d",sw);
    printf("\n");
    return 0;
}
int selectionSort(int a[],int n){
    int i,j,sw=0,minj,t;
    for(i=0;i<n;i++){
        minj=i;
        for(j=i;j<n;j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        if(minj!=i){
            t=a[i];
            a[i]=a[minj];
            a[minj]=t;
            sw++;
        }
    }
    return sw;
}
