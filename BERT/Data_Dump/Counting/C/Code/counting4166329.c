#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(void){
    unsigned short *a, *b;
    
    int c[VMAX+1];
    int n,i,j;
    scanf("%d", &n);
    
    a = malloc(sizeof(short)*n+1);
    b = malloc(sizeof(short)*n+1);
    
    for(i=0;i<=VMAX;i++) c[i]=0;
    for(i=0; i < n; i++){
        scanf("%hu",&a[i+1]);
        c[a[i+1]]++;
    }

    for(i=1;i<=VMAX;i++) c[i]=c[i]+c[i-1];
    
    for(j=0;j<=n;j++){
        b[c[a[j]]] = a[j];
        c[a[j]]--;
    }
    
    for(i=1;i<=n;i++){
        printf("%d",b[i]);
        if(i<n) printf(" ");
        else printf("\n"); 
    }
    
    return 0;
    
}
