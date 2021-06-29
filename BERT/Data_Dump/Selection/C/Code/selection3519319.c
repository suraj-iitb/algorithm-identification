#include <stdio.h>

void selectionSort(int num[],int n){
    int i,minj,j,tmp,count=0;
    for(i=0;i<n;i++){
        minj=i;
        for(j=i;j<n;j++){
            if(num[j]<num[minj]){
                minj=j;
            }
        }
        if(minj!=i){
            count++;
        }
        tmp=num[i];
        num[i]=num[minj];
        num[minj]=tmp;
    }
    for(j=0;j<n;j++){
        printf("%d%s",num[j],(j==n-1?"\n":" "));
    }
    printf("%d\n",count);
}

int main(void){
    int num[101];
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    selectionSort(num,n);
    return 0;
}

