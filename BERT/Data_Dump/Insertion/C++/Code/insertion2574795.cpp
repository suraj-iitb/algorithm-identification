#include <cstdio>
int main(void){
    int a[100+1],i,n,v,j,m;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        i==n-1?printf("%d\n",a[i]):printf("%d ",a[i]);
    }
    
    for(i=1;i<n;i++){
        v=a[i];
        j=i-1;
        while(j>=0&&a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        for(m=0;m<n;m++)m==n-1?printf("%d\n",a[m]):printf("%d ",a[m]);
    }
    return 0;
}
