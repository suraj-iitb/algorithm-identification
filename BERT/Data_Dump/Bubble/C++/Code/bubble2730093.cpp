#include<stdio.h>
int main (){
    int n;
    scanf("%d",&n);
    int c[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&c[i]);
    }
    
    int cnt,x=0;
    for(int j=0;j<n;j++)
    {
    for(int i=n-1;i>0;i--)
        {
            if(c[i]<c[i-1])cnt=c[i],c[i]=c[i-1],c[i-1]=cnt,x++;
            else;
        }
    }
    for(int i=0;i<n-1;i++){
        printf("%d ",c[i]);
    }
    printf("%d\n%d\n",c[n-1],x);
    return 0;
}
