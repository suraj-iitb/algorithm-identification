#include<cstdio>
int a[101],b,k;
int main(){
    scanf("%d",&b);
    for(int i=0;i<b;++i)scanf("%d",a+i);
    for(int i=0;i<b-1;++i)printf("%d ",a[i]);
    printf("%d\n",a[b-1]);
    for(int i=1;i<b;++i){
        k=a[i];
        int j;
        for(j=i-1;j>=0&&a[j]>k;--j){
            a[j+1]=a[j];
        }
        a[j+1]=k;
        for(int i=0;i<b-1;++i)printf("%d ",a[i]);
        printf("%d\n",a[b-1]);
    }
    return 0;
}
