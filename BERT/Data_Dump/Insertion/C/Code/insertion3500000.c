#include <stdio.h>

void insertionSort(int num[],int n){
    int i,v,j;
    for(i=1;i<n;i++){
        v=num[i];
        j=i-1;
        while(j>=0&&num[j]>v){
            num[j+1]=num[j];
            j--;
            num[j+1]=v;
        }
        for(j=0;j<n;j++){
            printf("%d",num[j]);
            if(j!=n-1){
                printf(" ");
            }
        }
        printf("\n");
    }
} 

int main(void){
    int num[101];
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
        printf("%d",num[i]);
        if(i!=n-1){
            printf(" ");
        }
    }
    printf("\n");
    insertionSort(num,n);
    return 0;
}

