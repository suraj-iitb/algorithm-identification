#include <stdio.h>
int a[10001],n,m,x,sum=0,i,j;
int main(){
    scanf("%d",&n);
    for ( i = 0; i < n; ++i) scanf("%d",&a[i]);
    scanf("%d",&m);
    for (i = 0; i < m; ++i) {
        scanf("%d",&x);
        for ( j = 0; j < n; ++j)
            if(x==a[j]){
                sum++;
                break;
            }
    }
    printf("%d\n",sum);
    return 0;
}
