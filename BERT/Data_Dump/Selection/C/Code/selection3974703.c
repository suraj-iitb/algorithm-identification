#include <stdio.h>
#define S 100

int main(void)
{
    int i, j, n, N[S], c=0;
    int temp, min;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &N[i]);
    for(i=0; i<n-1; i++){
        min=i;
        for(j=i+1; j<n; j++){
            if(N[j]<N[min]) min=j;
        }
        if(min!=i){
         temp=N[min];
         N[min]=N[i];
         N[i]=temp;
         c++;
         }
    }
    for(i=0; i<n; i++){
        if(i==n-1) printf("%d\n", N[i]);
        else printf("%d ", N[i]);
    }
    printf("%d\n", c);
    return 0;
}
