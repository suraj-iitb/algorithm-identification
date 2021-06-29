#include<stdio.h>
int main(){
    int flag = 1, i, j, a[101]={},n, count = 0, tmp;
    scanf("%d", &n);
    for( i = 0; i < n; i++ ){
        scanf("%d", &a[i]);
    }
    while( flag ){
        flag = 0;
        for( j = n-1; j >= 1; j-- ){
            if( a[j] < a[j-1] ){
                tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                flag = 1;
                count += 1;
            }
        }
    }
    for( i = 0; i < n; i++ ){
        printf("%d", a[i]);
        if( i != n-1 ){
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n", count);
    return 0;
}
