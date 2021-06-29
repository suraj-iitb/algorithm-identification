#include<stdio.h>

int main(void){
    int n, v;
    scanf("%d", &n);

    int a[n];
    for(int i=0 ; i<n ; i++) scanf("%d", &a[i]);
    
    for(int i=0 ; i<n ; i++)
        if(i==n-1)  printf("%d\n", a[i]);
        else        printf("%d ", a[i]);

    for(int i=1 ; i<n ; i++){
        int j=i;
        while(j>0 && a[j-1] > a[j]){
            v=a[j-1], a[j-1]=a[j], 
            a[j]=v, j--;
        }
        for(int i=0 ; i<n ; i++)
            if(i==n-1)    printf("%d\n", a[i]);
            else            printf("%d ", a[i]);
    }
    return 0;
}
