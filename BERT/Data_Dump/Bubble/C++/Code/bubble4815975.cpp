#include <stdio.h>
int main(){
    int n,a[100],temp,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=0;i<n-1;i++){
        for(int j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
                ans++;
            }
        }
    }
    printf("%d",a[0]);
    for(int i=1;i<n;i++)printf(" %d",a[i]);
    printf("\n%d\n",ans);
}

