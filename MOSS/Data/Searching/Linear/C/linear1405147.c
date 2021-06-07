#include<stdio.h>
int main()
{
    int a,b,c,d=0,i,j;
    scanf("%d",&a);
    int x[a];
    for(i=0;i<a;i++){
        scanf("%d",&x[i]);
    }
    scanf("%d",&b);
    for(i=0;i<b;i++){
        scanf("%d",&c);
        for(j=0;j<a;j++){
            if(c==x[j]){
                d++;
                break;
            }
        }
    }
    printf("%d\n",d);
    return 0;
}
