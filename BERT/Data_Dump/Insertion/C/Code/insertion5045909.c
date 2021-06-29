#include <stdio.h>
int main(){

    int n,i,j,v;
    int array[100];

    scanf("%d",&n);
    for(i=0;i<=n-1;i++){
        scanf("%d",&array[i]);
    }

    for(i=0;i<=n-2;i++){
        printf("%d ",array[i]);
    }
    printf("%d\n",array[i]);

    for(i=1;i<=n-1;i++){
        v=array[i];
        j=i-1;
        while(j>=0&&array[j]>v){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=v;
        for(j=0;j<=n-2;j++){
            printf("%d ",array[j]);
        }
        printf("%d",array[j]);
        printf("\n");
    }
    return 0;
}

