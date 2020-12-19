#include <stdio.h>
int main(){
    int n,a[10000],bot,ans=0,temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        bot=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[bot])bot=j;
        if(bot!=i){
            ans++;
            temp=a[bot];
            a[bot]=a[i];
            a[i]=temp;
        }
        
    }
    printf("%d",a[0]);
    for(int i=1;i<n;i++)printf(" %d",a[i]);
    printf("\n%d\n",ans);
}
