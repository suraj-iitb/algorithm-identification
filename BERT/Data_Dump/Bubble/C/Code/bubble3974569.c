#include <stdio.h>
#define S 100

int main(void)
{
    int n, i, N[S], c=0, temp;
    int flag=1;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &N[i]);
    while(flag){
        flag=0;
    for(i=n-1; i>0; i--)
    {
        if(N[i]<N[i-1]){
            temp=N[i];
            N[i]=N[i-1];
            N[i-1]=temp;
            c++;
            flag=1;
        }
    }
    }
    for(i=0; i<n; i++){
        if(n-1==i) printf("%d\n", N[i]);
        else printf("%d ", N[i]);
    }
    printf("%d\n", c);
    return 0;
}
