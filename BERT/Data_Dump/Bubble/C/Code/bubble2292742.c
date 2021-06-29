#include<stdio.h>
int main()
{
    int a,b,c,d=0,i,j;
    scanf("%d",&a);
    int x[a];
    for(i=0;i<a;i++){
        scanf("%d",&x[i]);
    }
    for(i=0;i<a-1;i++){
        for(j=a-1;j>i;j--){
            if(x[j-1]>x[j]){
                c=x[j-1];x[j-1]=x[j];x[j]=c;
                d++;
            }
        }
    }
    for(i=0;i<a;i++){
        if(i==a-1)printf("%d\n",x[i]);
        else printf("%d ",x[i]);
    }
    printf("%d\n",d);
    return 0;
}
