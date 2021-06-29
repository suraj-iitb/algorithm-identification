#include<stdio.h>
#define N 100
int main(){
    int i,n,a[N],flag,key,count = 0;
    scanf("%d",&n);
    for( i = 0 ; i < n ; i++ ){
        scanf("%d",&a[i]);
    }
    flag = 1;
    while(flag){
        flag = 0;
        for( i = n - 1 ; i > 0 ; i-- ){
            if( a[i] < a[i - 1] ){
                key = a[i];
                a[i] = a[i - 1];
                a[i - 1] = key;
                flag = 1;
                count++;
            }
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
