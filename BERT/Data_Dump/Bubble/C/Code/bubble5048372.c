#include <stdio.h>
#define N 100
int main(){
    int array[N];
    int i, j, n, temp, cnt=0;

    scanf("%d ",&n);
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    for(i=0;i<n;i++){
        for(j=n-1;j>=i+1;j--){
            if(array[j]<array[j-1]){
                temp=array[j];
                array[j]=array[j-1];
                array[j-1]=temp;
                cnt++;
            }
        }
    }
    for(i=0;i<n-1;i++){
        printf("%d ",array[i]);
    }
    printf("%d\n",array[n-1]);
    printf("%d\n",cnt);
    return 0;
}
