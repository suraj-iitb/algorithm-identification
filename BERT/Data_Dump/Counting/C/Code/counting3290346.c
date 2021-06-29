#include<stdio.h>
#include<stdlib.h>
#define max(a,b) a>b?a:b

void CountingSort(int a[], int b[], int k, int n){
    int i;
    int *c;
    c=calloc(k+1, sizeof(int));
    for(i=0;i<=k;i++)c[i]=0;

    for(i=0;i<n;i++)c[a[i]]++;
    
    for(i=1;i<=k;i++)c[i]+=c[i-1];

    for(i=n-1;i>=0;i--){
        b[c[a[i]]]=a[i];
        c[a[i]]--;
    }
    free(c);
}

int main(void){
    int i;
    int n;
    int *x;
    int *y;
    int max_n=0;

    scanf("%d",&n);
    x=calloc(n,sizeof(int));
    y=calloc(n+1, sizeof(int));

    for(i=0;i<n;i++){
        scanf("%d",&x[i]);
        max_n=max(max_n,x[i]);
    }

    CountingSort(x,y,max_n, n);

    for(i=1;i<n;i++)printf("%d ", y[i]);
    printf("%d", y[i]);
    printf("\n");
}
