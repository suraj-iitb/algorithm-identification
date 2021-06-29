#include<stdio.h>

int main(void){
    int n;
    scanf("%d",&n);
    int num[n+1];
    int q;
    for(q=0;q<=n-1;q++) scanf("%d",&num[q]);
    int ans=0;
    int i,j;
    for(i=0;i<=n-1;i++){
        
        for(j=n-1;j>=i+1;j--){
            if(num[j-1]>num[j]){
                int a;
                a=num[j-1];
                num[j-1]=num[j];
                num[j]=a;
                ans++;
            }
        }
        
    }
    int b;
    for(b=0;b<=n-2;b++)printf("%d ",num[b]);
    printf("%d\n",num[n-1]);
    printf("%d\n",ans);
    
    return 0;
}
