
#include<stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    int num[n+1];
    int i;
    for(i=0;i<=n-1;i++) scanf("%d",&num[i]);
    int j,k;
    for(j=0;j<=n-1;j++){
        int v=num[j];
        k=j-1;
        while(k>=0 && v<num[k]){
            num[k+1]=num[k];
            k--;
        }
        num[k+1]=v;
        
        int a;
        for(a=0;a<=n-2;a++) printf("%d ",num[a]);
        printf("%d\n",num[n-1]);
    }

    return 0;
}
