/*
 * FileName:     selection_sort
 * CreatedDate:  2020-07-08 13:45:37 +0900
 * LastModified: 2020-07-08 13:51:46 +0900
 */

#include <stdio.h>
#include <stdlib.h>
int selectionSort( int *a, int n){
    int cnt = 0;
    for( int i=0; i<n; i++){
        int minj = i;
        for( int j=i; j<n; j++){
            if(a[j]<a[minj]){
                minj = j;
            }
        }
        if( minj!=i ){
            cnt++;
        }
        int tmp = a[minj];
        a[minj] = a[i];
        a[i] = tmp;
    }
    return cnt;
}
int main(void){
    int n;scanf("%d", &n);
    int *a = malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d", a+i);
    int ans = selectionSort( a, n);
    printf("%d", a[0]);
    for(int i=1; i<n; i++){
        printf(" %d", a[i]);
    }
    printf("\n%d\n", ans);
    free(a);
    return 0;
}

