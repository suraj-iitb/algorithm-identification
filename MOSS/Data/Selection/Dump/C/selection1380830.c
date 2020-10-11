#include<stdio.h>
int main()
{
    int a,b,minj,c=0,i,j;
    scanf("%d",&a);
    int x[a];
    for(i=0;i<a;i++){
        scanf("%d",&x[i]);
    }
    for(i=0;i<a;i++){
        minj=i;
        for(j=i;j<a;j++){
            if(x[j]<x[minj]){
                minj=j;
            }
        }
        if(i!=minj){
        b=x[i];x[i]=x[minj];x[minj]=b;
        c++;
        }
    }
    for(i=0;i<a;i++){
        if(i==a-1)printf("%d\n",x[i]);
        else printf("%d ",x[i]);
    }
    printf("%d\n",c);
    return 0;
}
