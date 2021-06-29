#include<stdio.h>

int main(void){
    int n, tmp, c=0;
    scanf("%d", &n);
    int a[n];
    for(int i=0 ; i<n ; i++) scanf("%d",&a[i]);
    
    for(int i=0 ; i<n ; i++){
        for(int j=n-1 ; j>i ; j--){
            if(a[j]<a[j-1]){
                tmp = a[j], a[j] = a[j-1], 
                a[j-1] = tmp, c++;
            }
        }
    }
    for(int i=0 ; i<n ; i++){
        if(i==n-1)  printf("%d\n", a[i]);
        else        printf("%d ", a[i]);
    }
    printf("%d\n", c);
    return 0;
}
