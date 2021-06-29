#include <stdio.h>
int main(void){
    int n;
    int a[101]={0};
    int i,j,tmp=0,cnt=0;
    
    scanf("%d",&n);
    for(i=1; i<=n; i++){
        scanf("%d",&a[i]);
    }
    
    for(i=1; i<=n-1; i++){
        for(j=1; j<=n-i; j++){
            if(a[j]>a[j+1]){
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
                cnt++;
            }
        }
    }
    
    for(i=1; i<=n; i++){
        if(i!=n)printf("%d ",a[i]);
        if(i==n)printf("%d\n",a[i]);
    }
    printf("%d\n",cnt);
    
    return 0;
}
