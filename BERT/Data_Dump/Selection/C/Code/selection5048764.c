#include <stdio.h>
#define N 100

int main(){
    int array[N];
    int i, j, n, temp, minj, flag=0, cnt=0;

    scanf("%d ",&n);
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    for(i=0;i<n;i++){
        minj=i;
        for(j=i;j<=n-1;j++){
            if(array[j]<array[minj]){
                minj=j;
            }
        }
        if(array[i]>array[minj]){
            cnt++;
        }
        temp=array[minj];
        array[minj]=array[i];
        array[i]=temp;
    }
    for(i=0;i<n-1;i++){
        printf("%d ",array[i]);
    }
    printf("%d\n",array[n-1]);
    printf("%d\n",cnt);
    return 0;

}
