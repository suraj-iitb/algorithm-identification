#include<stdio.h>
int main(void) {
    int i, n, j, l, k, m, a[100], v, key;
    scanf("%d", &n);
    
    for(i=0;i<n;i++){
             scanf("%d",&a[i]);
                     }

    for ( i = 0; i < n; i++ ) {
        v = a[i];
        j = i - 1;
       
        for(j;j>=0&&a[j]>v;j--){
                                a[j+1]=a[j];
                                                              
                                }
        a[j + 1] = v;
        printf("%d", a[0]);
        for ( l = 1; l < n; l++ ) printf(" %d", a[l]);
        printf("\n");
    }
 
}
