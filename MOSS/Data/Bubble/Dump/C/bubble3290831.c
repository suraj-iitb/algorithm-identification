#include <stdio.h>
int a[110];
int main(){
    int n,i,j,cnt=0,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        for(j=n;j>i;j--)
            if(a[j]<a[j-1])t=a[j],a[j]=a[j-1],a[j-1]=t,cnt++;
    for(i=1;i<=n;i++){
        if(i!=1)printf(" ");
        printf("%d",a[i]);
    }
    printf("\n%d\n",cnt);
    return 0;
}

