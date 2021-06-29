#include<cstdio>
int a[101],cnt,n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",a+i);
    for(int i=0;i<n;++i)
        for(int j=n-1;j>i;--j)
            if(a[j]<a[j-1]){
                int t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
                ++cnt;
            }
    for(int i=0;i<n-1;++i)printf("%d ",a[i]);
    printf("%d\n%d\n",a[n-1],cnt);
    return 0;
}

