#include<stdio.h>

int main(void){
    int n, tmp, minj;
    scanf("%d", &n);
    int a[n];
    for(int i=0 ; i<n ; i++) scanf("%d",&a[i]);
    int c=0;
    for(int i=0 ; i<n-1 ; i++){
        minj=i;
        for(int j=i ; j<n ; j++)
            if(a[j]<a[minj]) minj=j;
        tmp=a[i], a[i]=a[minj] , a[minj]=tmp;
        if(i!=minj) c++;
    }
    for(int i=0 ; i<n ; i++){
        if(i==n-1)  printf("%d\n", a[i]);
        else        printf("%d ", a[i]);
    }
    printf("%d\n", c);
    return 0;
}
