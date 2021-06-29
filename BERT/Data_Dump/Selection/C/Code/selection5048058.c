#include<stdio.h>
#define N 100
int main(){
    int i,j,n,a[N],key,count = 0,min;
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&a[i]);
    }
    for( i = 0 ; i < n ; i++ ){
        min = i;
        for( j = i ; j < n ; j++ ){
            if(a[j] < a[min]){
                min = j;
            }
        }
        if( i != min ){
            key = a[i];
            a[i] = a[min];
            a[min] = key;
            count++;
        }
    }
    for( i = 0 ; i < n ; i++ ){
        printf("%d",a[i]);
        if( i < n - 1 ) printf(" ");
    }
    printf("\n");
    printf("%d\n",count);
    return 0;
}
