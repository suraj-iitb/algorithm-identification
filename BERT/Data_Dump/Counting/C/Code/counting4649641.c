/*
 * FileName:     counting_sort
 * CreatedDate:  2020-07-07 16:45:13 +0900
 * LastModified: 2020-07-07 17:10:24 +0900
 */

#include <stdio.h>
#include <stdlib.h>
void counting_sort( int *a, int *b, int n, int k){
    int c[k];
    for(int i=0;i<k;i++){
        c[i]=0;
    }
    for(int i=1; i<n+1; i++){
        c[a[i]]++;
    }
    for(int i=1;i<k;i++){
        c[i] += c[i-1];
    }
    for(int i=n; i>0; i--){
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
}
int main(void){
    int n;scanf("%d ", &n);
    int *a = malloc((n+1)*sizeof(int));
    int a_max = 0;
    for(int i=1;i<n+1;i++){
        scanf("%d", a+i);
        if(a_max<a[i]){
            a_max = a[i];
        }
    }
    int *b = malloc((n+1)*sizeof(int));
    counting_sort( a, b, n, a_max+1);
    printf("%d", b[1]);
    for(int i=2; i<n+1; i++){
        printf(" %d", b[i]);
    }
    printf("\n");
    free(a);
    free(b);
    return 0;
}

