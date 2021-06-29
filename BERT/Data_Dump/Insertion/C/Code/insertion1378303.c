#include<stdio.h>
int main()
{
    int a,b,i,j,k;
    scanf("%d",&a);
    int x[a];
    for(i=0;i<a;i++){
        scanf("%d",&x[i]);
    }
    for(i=0;i<a;i++){
        b=x[i];
        j=i-1;
        while(j>=0&&x[j]>b){
            x[j+1]=x[j];
            j--;
            x[j+1]=b;
        }
        for(k=0;k<a;k++){
            if(k==a-1)printf("%d\n",x[k]);
            else printf("%d ",x[k]);
        }
    }
    return 0;
}
