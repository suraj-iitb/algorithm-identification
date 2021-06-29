#include <stdio.h>
#include <stdlib.h>
int main(void){
    int a[10001],n,i,k;
    int *b;
    for(i=0;i<10001;i++){
        a[i]=0;
    }
    scanf("%d",&n);
    b = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",&k);
        a[k]++;
    }
    k=0;
    for(i=0;i<10001;){
        if(a[i]==0){
            i++;
        }else{
            b[k] = i;
            a[i]--;
            k++;
        }
    }
    for(i=0;i<n;i++){
        printf("%d",b[i]);
        if(i!=n-1){
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}

