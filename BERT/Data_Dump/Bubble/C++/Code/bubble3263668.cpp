#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,a[110],c,tmp=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=n-1;i>=0;i--)
    for(int j=1;j<=i;j++){
        if(a[j-1]>a[j]){
            c=a[j-1];
            a[j-1]=a[j];
            a[j]=c;
            tmp++;
        }
    }
    for(int i=0;i<n;i++){
            if(i<n-1)printf("%d ",a[i]);
            else printf("%d\n",a[i]);
    }
    printf("%d\n",tmp);
    return 0;
}

